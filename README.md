# Tetris Clone (C++ & SDL2)

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://en.cppreference.com/)
[![SDL2](https://img.shields.io/badge/SDL2-2.0.22%2B-orange.svg)](https://www.libsdl.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A simple Tetris clone written in C++ using the SDL2 library. This was built from scratch to practice rendering, input handling, and classic game logic without a game engine.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Controls](#controls)
- [Project Structure](#project-structure)
- [Roadmap](#roadmap)
- [License](#license)
- [Author](#author)

---

## Overview

This is a functional implementation of the classic Tetris game, using SDL2 and C++. It's an educational project with core gameplay mechanics, simple rendering, and state transitions (main menu, playing, game over).

---

## Features

- 🎮 Classic Tetris mechanics
- 📦 Piece movement, rotation, and hard drop
- 🧱 Grid-based board with collision detection
- 🔄 Real-time piece locking and new piece generation
- ❌ Game over detection
- 🖼️ Main menu and Game Over screens using SDL_ttf
- 🎨 Each piece has its own color and outline

---

## Installation

### 🛠️ Prerequisites

Make sure you have:

- C++17 or later
- SDL2
- SDL2_ttf

### 🧱 Build and Run

```bash
git clone https://github.com/0x-4b/tetris-sdl.git
cd tetris-sdl

# Build manually (Linux/macOS):
g++ src/*.cpp -o tetris -lSDL2 -lSDL2_ttf

# or with Makefile
make

# Run the game
./tetris
```

> Make sure you have `./data/font.ttf` in the right place or update the path in `main.cpp`.

---

## Controls

| Key       | Action                  |
|-----------|-------------------------|
| ⬅️ / ➡️   | Move left / right        |
| ⬇️        | Soft drop               |
| `x`       | Hard drop (lock piece)  |
| `z`       | Rotate piece            |
| `ESC`     | Return to main menu     |
| Any key   | Start or continue       |

---

## Project Structure

```
tetris-sdl/
├── src/
│   ├── main.cpp
│   ├── Game.cpp / Game.h
│   ├── Board.cpp / Board.h
│   ├── Pieces.cpp / Pieces.h
│   ├── IO.cpp / IO.h
│   ├── Font.cpp / Font.h
├── data/
│   └── font.ttf
├── Makefile
├── LICENSE
└── README.md
```

---

## Roadmap

- [ ] Add score and level tracking
- [ ] Ghost piece (drop preview)
- [ ] Hold piece feature
- [ ] Sound effects and background music
- [ ] Pause functionality
- [ ] WebAssembly build via Emscripten

---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Author

**0x-4b**  
GitHub: [@0x-4b](https://github.com/0x-4b)
