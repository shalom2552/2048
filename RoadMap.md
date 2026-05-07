
# Road Map

## Critical

- [x] **#1** Missing virtual destructor in `Menu` — `inc/menu/menu.hpp`
- [x] **#4** `Board` depends on `InputEvent` (wrong layer) — decouple with `Direction` enum, map in `game.cpp`

## High

- [x] **#2** `enum` → `enum class` everywhere — `inc/types.hpp`
- [x] **#3** RAII `Terminal` class for terminal state — `main.cpp`, `inc/input.hpp`
- [x] **Signal** `handle_sigint` calls `exit(0)` — destructor never runs; fix with `restore_terminal()` + re-raise
- [ ] **#8** `m_items` in `Menu` should be `private` with protected accessor — `inc/menu/menu.hpp`
- [ ] **#19** `merged` flag never set `true` in `collapse_line` — double-merge prevention broken, `src/board.cpp`
- [ ] **Display** `IMenuRenderer` interface — replace `display_menu` / `display_settings_menu` duplication

## Medium

- [ ] **#5** `[[nodiscard]]` missing on getters — `inc/board.hpp`, `inc/menu/menu.hpp`
- [ ] **#6** `explicit` missing on single-arg constructors — `inc/game.hpp`, `inc/menu/settings_menu.hpp`
- [ ] **#7** `const` missing on Board query methods (`get_score`, `changed`, `has_valid_move`) — `inc/board.hpp`
- [ ] **#9** Remove redundant `m_items_count` — use `m_items.size()` — `inc/menu/menu.hpp`
- [ ] **#13** `MenuItem::value = -1` sentinel → `std::optional<int>` — `inc/types.hpp`
- [ ] **#15** `GameSettings` has no validation — add bounds check for `board_size`

## Low

- [ ] **#10** `std::unique_ptr<Board>` → value member — `inc/game.hpp`
- [ ] **#11** `rand()` without seed → replace with `<random>` / `std::mt19937` — `src/board.cpp`
- [ ] **#12** `save_board_size()` is dead code — remove, call `exit_menu()` directly — `src/menu/settings_menu.cpp`
- [ ] **#14** `MenuItem` id field — document or strengthen type safety — `inc/types.hpp`
- [ ] **#17** `print_padding` / `print_left_padding` duplication — unify — `src/display/common_display.cpp`
- [ ] **#20** Split `constants.hpp` grab-bag into `ansi.hpp`, `keys.hpp`, `layout.hpp`
- [ ] **#21** `const std::string` / `const std::vector` in header → `inline constexpr` or `extern` — `inc/constants.hpp`
- [ ] **#22** `fall-through` in `run_menu()` switch — add `break` — `src/menu/menu.cpp`
- [ ] **#23** Typos: `HEADER_PAADING`, `BOX_LEFT_PADNG`; rename `print_char` → `print_str`; `forward` → `collapse_to_start`
- [ ] **#24** C-style cast `(int)m_size` → `static_cast<int>(m_size)` — `src/board.cpp`

## Refactoring

- [ ] Extract `MenuItem` to its own class
