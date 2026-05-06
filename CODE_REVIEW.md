# Code Review — Design & Refactoring

Focused on SOLID, DRY, C++ class design rules, and extensibility.
Goal: easy to add or change things without touching existing code.

---

## Architecture: Current vs Proposed

```
CURRENT
────────────────────────────────────────────
main.cpp
  ├── input_setup() / cleanup()   ← raw functions, no RAII
  └── MainMenu
        ├── Menu (base)
        │     └── display_menu()  ← free function, hardcoded
        └── SettingsMenu
              └── display_settings_menu()  ← duplicate free function

Board ← depends on InputEvent    ← wrong layer dependency

PROPOSED
────────────────────────────────────────────
main.cpp
  └── TerminalGuard (RAII)        ← auto cleanup on any exit
  └── MainMenu

Board ← depends on Direction     ← clean, no input knowledge

Menu (base)
  ├── IMenuRenderer (injected)    ← abstract, swappable
  ├── MainMenu → DefaultRenderer
  └── SettingsMenu → SettingsRenderer
```

---

## Question: Display in Classes or Free Functions?

**Short answer:** keep the low-level print utilities as free functions.
Move the "how a menu looks" into a `IMenuRenderer` interface.

**Why free functions are fine for utilities:**
`print_char`, `print_line`, `print_header` — these are stateless, pure output. Free functions
are the right tool. No class needed.

**Why "how a menu renders" should be a class:**
Rendering behavior varies per menu type. That variation is exactly what polymorphism solves.
Currently `display_menu()` and `display_settings_menu()` share ~80% code and grow together
forever. Every new menu type adds another near-duplicate function.

**The fix — Renderer interface (DIP + OCP):**

```cpp
// inc/display/i_menu_renderer.hpp
class IMenuRenderer {
public:
    virtual void render(std::vector<MenuItem> const& items,
                        std::size_t selected) const = 0;
    virtual ~IMenuRenderer() = default;
};
```

```cpp
// Menu base gets a renderer injected
class Menu {
public:
    explicit Menu(std::unique_ptr<IMenuRenderer> renderer);
private:
    void display();  // calls m_renderer->render(m_items, m_selected)
    std::unique_ptr<IMenuRenderer> m_renderer;
};
```

Adding a new menu display = write one new renderer class. Zero changes to `Menu`, zero
changes to existing renderers. That is the Open/Closed Principle in practice.

The shared 80% (clear screen, header, footer, highlight loop) lives in a base renderer:

```cpp
class BaseMenuRenderer : public IMenuRenderer {
protected:
    void render_frame(std::vector<MenuItem> const& items,
                      std::size_t selected) const;
    virtual void render_item(MenuItem const& item, bool is_selected) const = 0;
};

class DefaultRenderer  : public BaseMenuRenderer { ... };
class SettingsRenderer : public BaseMenuRenderer { ... };
```

No more duplication. Shared code in one place.

---

## C++ Class Design Issues

### 1. Missing Virtual Destructor in `Menu` (Critical)

**File:** `inc/menu/menu.hpp`

`Menu` has virtual methods but no virtual destructor. If a derived menu is ever held through
a `Menu*` and deleted, the destructor of the derived class is never called — undefined behavior.

```cpp
class Menu {
public:
    virtual ~Menu() = default;  // ← required in every polymorphic base class
```

**Rule:** any class with a virtual method must have a virtual destructor.

---

### 2. `enum` Should Be `enum class` (Type Safety)

**File:** `inc/types.hpp`

```cpp
// current — leaks names into global scope, implicit int conversion
enum InputEvent { INPUT_UP, INPUT_DOWN, ... };
enum MainMenuOptions { MM_START, MM_SETTINGS, ... };

// proposed — scoped, no implicit conversion
enum class InputEvent { Up, Down, Right, Left, Select, Quit };
enum class MainMenuOption { Start, Settings, Help, Quit };
enum class SettingsMenuOption { BoardSize, Back };
enum class Direction { Up, Down, Left, Right };
```

`enum class` prevents accidental comparison between different enum types and keeps names
out of global scope. It also makes the intent explicit at every call site.

---

### 3. No RAII for Terminal State

**File:** `main.cpp`, `inc/input.hpp`

```cpp
// current — manual, fragile
int main() {
    input_setup();
    MainMenu menu;
    menu.run_menu();
    cleanup();   // never called if run_menu() throws
}
```

If anything between `input_setup()` and `cleanup()` throws or returns early,
the terminal is left in raw mode — cursor hidden, no echo. Broken terminal for the user.

```cpp
// proposed — RAII guarantees cleanup
class TerminalGuard {
public:
    TerminalGuard()  { input_setup(); }
    ~TerminalGuard() { cleanup(); }
    TerminalGuard(TerminalGuard const&) = delete;
    TerminalGuard& operator=(TerminalGuard const&) = delete;
};

int main() {
    TerminalGuard terminal;  // ← cleanup guaranteed, no matter what
    MainMenu menu;
    menu.run_menu();
}
```

**Rule:** any resource that needs manual release (file, socket, terminal state, lock)
belongs in a RAII wrapper.

---

### 4. `Board` Depends on `InputEvent` (Wrong Layer / SRP)

**File:** `inc/board.hpp`, `src/board.cpp`

```cpp
void Board::collapse_move(InputEvent direction);
```

`Board` is game logic. `InputEvent` is input/UI. Board now depends on the input layer —
if the input system changes, Board must change too. These layers should not know each other.

```cpp
// board.hpp — add this
enum class Direction { Up, Down, Left, Right };

// board.hpp
void collapse(Direction dir);

// game.cpp — game layer maps input to direction
std::optional<Direction> to_direction(InputEvent e) {
    switch (e) {
        case InputEvent::Up:    return Direction::Up;
        case InputEvent::Down:  return Direction::Down;
        case InputEvent::Left:  return Direction::Left;
        case InputEvent::Right: return Direction::Right;
        default: return std::nullopt;
    }
}
```

---

### 5. `[[nodiscard]]` Missing on Getters

**Files:** `inc/board.hpp`, `inc/menu/menu.hpp`

When a function returns a value that the caller should always use, mark it `[[nodiscard]]`.
The compiler will warn if the return value is silently discarded.

```cpp
// board.hpp
[[nodiscard]] std::size_t size() const;
[[nodiscard]] unsigned int get_score() const;
[[nodiscard]] bool changed() const;
[[nodiscard]] bool has_valid_move() const;

// menu.hpp
[[nodiscard]] std::size_t get_menu_selection() const;
```

---

### 6. `explicit` Missing on Constructors

**Files:** `inc/game.hpp`

Single-argument constructors should be `explicit` to prevent accidental implicit conversions.

```cpp
// game.hpp
explicit Game(GameSettings settings);

// settings_menu.hpp
explicit SettingsMenu(GameSettings const& settings);
```

`Board` already has `explicit` — apply the same rule everywhere.

---

### 7. Missing `const` on Methods

**File:** `inc/board.hpp`

These are pure queries that don't modify state:

```cpp
unsigned int get_score();    // should be: unsigned int get_score() const;
bool changed();              // should be: bool changed() const;
bool has_valid_move();       // should be: bool has_valid_move() const;
```

Without `const`, these methods can't be called on a `Board const&`, which breaks
passing boards by const reference to display functions.

---

### 8. `m_items` Should Be `private` with Protected Accessor

**File:** `inc/menu/menu.hpp`

```cpp
protected:
    std::vector<MenuItem> m_items;  // ← derived classes can do anything to this
```

`SettingsMenu` directly writes `m_items[SM_BOARD_SIZE].value = m_board_size;`.
A derived class can insert items, reorder, clear, or corrupt the vector.

```cpp
private:
    std::vector<MenuItem> m_items;

protected:
    MenuItem& get_item(std::size_t index);           // controlled write access
    MenuItem const& get_item(std::size_t index) const;
```

---

### 9. `m_items_count` is Redundant State

**File:** `inc/menu/menu.hpp`, `src/menu/menu.cpp`

```cpp
std::size_t m_items_count = 0;  // manually incremented in add_item()
```

`m_items` is a `std::vector`. Its size is always available via `m_items.size()`.
Two sources of truth for the same value — they can go out of sync.

Delete `m_items_count`. Replace all uses with `m_items.size()`.

---

### 10. Score Recomputed Every Frame (Inefficiency)

**File:** `src/board.cpp`

```cpp
unsigned int Board::get_score() {
    unsigned int score = 0;
    for (auto& row : m_board)
        for (auto& cell : row)
            score += cell.value;
    return score;
}
```

This iterates the full board on every render. For a large board it's wasteful.
Score only changes when cells merge. Track it incrementally:

```cpp
private:
    unsigned int m_score = 0;  // add merged value inside collapse_line()

public:
    unsigned int get_score() const { return m_score; }
```

---

### 11. `rand()` Without Seed

**File:** `src/board.cpp`

`rand()` produces the same sequence every run because `srand()` is never called.
Replace with `<random>`:

```cpp
void Board::generate_new_cell() {
    std::size_t count = count_empty_cells();
    if (count == 0) return;

    static std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<std::size_t> dist(0, count - 1);
    place_empty_cell(dist(rng));
}
```

---

### 12. `std::unique_ptr<Board>` Unnecessary

**File:** `inc/game.hpp`

```cpp
std::unique_ptr<Board> m_board;  // heap allocation, no polymorphism
```

`Board` is not a base class. No reason for heap allocation. Value semantics are simpler,
faster, and clearer about ownership:

```cpp
Board m_board;  // compiler manages lifetime, no indirection
```

If `Board` needs to be initialized after construction (not in initializer list),
use `std::optional<Board>` — still no heap.

---

### 13. `MenuItem::value = -1` Sentinel

**File:** `inc/types.hpp`

```cpp
struct MenuItem {
    int value = -1;  // -1 = no value
};
```

Sentinel values are implicit contracts invisible in the type. Any code that forgets
the convention will treat -1 as a valid board size. Use `std::optional`:

```cpp
#include <optional>

struct MenuItem {
    int id;
    std::string title;
    std::optional<int> value = std::nullopt;
};
```

Now the presence/absence of a value is explicit and checked by the compiler:
```cpp
if (item.value.has_value()) { /* show spinner */ }
```

---

### 14. `enum class` IDs in `MenuItem` (Type Safety)

**File:** `inc/types.hpp`

```cpp
struct MenuItem {
    const int id;  // could be any int — no type information
```

`id` is always one of the menu option enums. Using `int` loses that information.
After converting to `enum class`, `id` can stay `int` for the base class
(since it serves different enums), but document the contract clearly.
Alternatively, template the base or use a variant.

---

### 15. `GameSettings` Has No Validation

**File:** `inc/types.hpp`, `inc/board.hpp`

```cpp
struct GameSettings {
    int board_size = 4;  // what if 0? what if 1?
};
```

`Board` accepts any size. A `board_size` of 0 or 1 crashes or produces nonsense.
Add validation at the boundary:

```cpp
// Option A: validate in GameSettings constructor
struct GameSettings {
    explicit GameSettings(int size = 4);
private:
    int board_size;
};

// Option B: validate in Board constructor (assert or throw)
Board::Board(std::size_t size) {
    assert(size >= 2 && size <= 8);
    ...
}
```

---

### 16. `display_menu` / `display_settings_menu` Duplication (DRY)

**File:** `src/display/menu_display.cpp`

~80% of both functions is identical. Every new menu adds another near-duplicate.
Solved entirely by the `IMenuRenderer` design described at the top.

---

### 17. `print_padding` vs `print_left_padding` Duplication (DRY)

**File:** `src/display/common_display.cpp`

```cpp
void print_padding(int padding)          { std::cout << std::string(padding, '\t'); }
void print_left_padding(unsigned int p)  { print_char(std::string(p, '\t')); }
```

Same output. Different types. One bypasses `print_char`. Delete one, unify the signature.

---

### 18. `save_board_size()` is Dead Code

**File:** `src/menu/settings_menu.cpp`

`update_board_size()` already syncs `m_board_size` and `m_items[...].value`.
`save_board_size()` reassigns the same value and exits. The assignment is a no-op.

Remove `save_board_size()`. Call `exit_menu()` directly from `handle_select`.

---

### 19. `merged` Flag Never Set `true` in `collapse_line`

**File:** `src/board.cpp`

```cpp
bool merged = false;
...
} else if (!merged && value == result[write - 1]) {
    result[write - 1] += value;   // merge happens here
                                  // merged should be set true — but isn't
} else {
    result[write++] = value;
    merged = false;               // only ever set false
}
```

The double-merge prevention is non-functional. After the merge branch, add:
```cpp
merged = true;
```

---

### 20. `constants.hpp` Grab-Bag (SRP)

**File:** `inc/constants.hpp`

All unrelated constants in one file. Split by concern:

| New File | Contents |
|----------|----------|
| `inc/ansi.hpp` | color codes, box-drawing chars, clear code |
| `inc/keys.hpp` | KEY_UP, KEY_DOWN, KEY_QUIT etc. |
| `inc/layout.hpp` | padding values, BOX_CELL_WIDTH, board limits |

---

### 21. `const std::string` / `const std::vector` in Header (ODR)

**File:** `inc/constants.hpp`

```cpp
const std::string ANSI_COLOR_RESET = "\033[0m";
const std::vector<std::string> CELL_COLORS = { ... };
```

Each `.cpp` that includes this header gets its own copy. Multiple definitions,
wasted memory, longer compile time.

C++17 fix: `inline constexpr` for string literals, or move to `.cpp` with `extern` in header.

```cpp
inline constexpr const char* ANSI_COLOR_RESET = "\033[0m";
```

For `CELL_COLORS` (a vector), move to `.cpp` + `extern` declaration in header.

---

### 22. `fall-through` in `run_menu()` switch

**File:** `src/menu/menu.cpp`

```cpp
case INPUT_SELECT: handle_select();
default: break;
```

Missing `break`. Falls through. Add `break` or mark intentional with `[[fallthrough]]`.

---

### 23. Naming Issues

**File:** `inc/constants.hpp`, `inc/display/common_display.hpp`

| Current | Problem | Fix |
|---------|---------|-----|
| `HEADER_PAADING` | typo (double A) | `HEADER_PADDING` |
| `BOX_LEFT_PADNG` | typo (missing I) | `BOX_LEFT_PADDING` |
| `print_char(std::string const&)` | takes string, not char | `print_str` or `print` |
| `forward` in `collapse_line` | ambiguous direction | `collapse_to_start` |

---

### 24. C-Style Cast in `collapse_line`

**File:** `src/board.cpp`

```cpp
for (int row = 0; row < (int)m_size; ++row) {
```

Use `static_cast<int>(m_size)`. C-style casts bypass type safety checks.

---

## Priority Order

| Priority | # | Issue |
|----------|---|-------|
| Critical | 1 | Missing virtual destructor in `Menu` |
| Critical | 4 | `Board` depends on `InputEvent` — wrong layer |
| High | 2 | `enum` → `enum class` everywhere |
| High | 3 | RAII `TerminalGuard` for terminal state |
| High | 8 | `m_items` protected — make private with accessor |
| High | 19 | `merged` never set true in `collapse_line` |
| High | Display | `IMenuRenderer` interface — OCP for display |
| Medium | 5 | `[[nodiscard]]` on getters |
| Medium | 6 | `explicit` on constructors |
| Medium | 7 | `const` on Board query methods |
| Medium | 9 | Remove redundant `m_items_count` |
| Medium | 13 | `MenuItem::value` → `std::optional<int>` |
| Medium | 15 | `GameSettings` validation |
| Medium | 16 | display function duplication (solved by IMenuRenderer) |
| Low | 10 | `unique_ptr<Board>` → value member |
| Low | 11 | `rand()` → `<random>` |
| Low | 12 | `save_board_size()` dead code |
| Low | 17 | padding function duplication |
| Low | 18 | `save_board_size` redundant |
| Low | 20 | split `constants.hpp` |
| Low | 21 | `const` string/vector in header (ODR) |
| Low | 22–24 | naming, typos, cast style |
