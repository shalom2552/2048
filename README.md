# 2048

Terminal-based 2048 game written in C++17.

## Status

- [x] Display
- [x] Input
- [x] Game Logic
- [x] Score System
- [x] Colors
- [x] Main Menu
- [ ] End Menu
- [ ] Max score

## Screenshots

<div align="center">
  <table>
    <tr>
      <td valign="top" width="50%">
        <h3 align="center">MainMenu</h3>
<img width="400" height="400" alt="MainMenu" src="https://github.com/user-attachments/assets/837d9030-d25a-4f9b-8cf5-309f5ea49540" />
      </td>
      <td valign="top" width="50%">
        <h3 align="center">Gameplay</h3>
<img width="400" height="400" alt="Gameplay" src="https://github.com/user-attachments/assets/5c2f9fd8-f8fd-4d07-b8e5-f813a61c5baa" />
      </td>
    </tr>
  </table>
</div>

## Build

```sh
git clone https://github.com/shalom2552/2048.git
cd 2048
make
```

## Run

```sh
./game
```

## Controls

### Game
| Key | Action |
|-----|--------|
| `w` / `↑` | Move up |
| `s` / `↓` | Move down |
| `a` / `←` | Move left |
| `d` / `→` | Move right |
| `q` | Quit to menu |

### Menu
| Key | Action |
|-----|--------|
| `w` / `↑` | Navigate up |
| `s` / `↓` | Navigate down |
| `a` / `←` | Decrease value |
| `d` / `→` | Increase value |
| `Enter` | Select |
| `q` | Exit |

## Project Structure

```
src/
  ├── board.cpp          — game logic, collapse moves, scoring
  ├── game.cpp           — game loop
  ├── input.cpp          — raw terminal input, key mapping
  ├── display/           — all rendering (board, menus, common)
  └── menu/              — menu base class, main menu, settings menu
```
