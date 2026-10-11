# Life like cellular automata on raylib

A cellular automata simulator written in C++ using [raylib](https://www.raylib.com/).
Draw cells, zoom and pan across an effectively infinite grid, and watch Conway's
Game of Life evolve — all rendered at a smooth 60 FPS.

## Features

- **Click to draw / erase cells** — left-click toggles a cell between alive and dead.
- **Camera controls** — pan with `W` `A` `S` `D`, zoom with the mouse wheel.
- **Pause / resume** — press `Space` to start and stop the simulation.
- **Configurable simulation speed** — the update rate is a single tweakable constant.
- **Fast grid rendering** — the static grid is baked into a render texture once,
  so it's not redrawn every frame.
- **Life-like rules** — implements the classic Conway rules (born with 3 neighbors,
  survives with 2 or 3), ready to be extended to other life-like rule sets.

## Controls

| Input              | Action                          |
|--------------------|---------------------------------|
| Left mouse click   | Toggle a cell alive / dead      |
| `W` `A` `S` `D`    | Pan the camera                  |
| Mouse wheel        | Zoom in / out                   |
| `Space`            | Pause / resume the simulation   |

## Building

The project uses the raylib quickstart layout with a Makefile.

### Linux / macOS

```sh
cd build
./premake5 gmake        # on macOS use: ./premake5.osx gmake
cd ..
make
```

The built binary is placed in the `bin/` directory.

### Windows

- MinGW-W64: run `build-MinGW-W64.bat`, then `make`.
- Visual Studio: run `build-VisualStudio2022.bat` (or `build-VisualStudio2026.bat`)
  and open the generated solution.

## Requirements

- A C++17 compiler (GCC, Clang, or MSVC)
- [raylib](https://www.raylib.com/) (bundled as a submodule in the build tree)
- `make` and [premake5](https://premake.github.io/) for the build system

## Project structure

```
src/
├── main.cpp       # Window setup, main loop, and render-texture grid
├── cells.h/.cpp   # Grid drawing, cell logic, and simulation rules
└── canvas.h/.cpp  # Camera pan/zoom and pause handling
```

## License

This project is based on the raylib quickstart template (CC0 1.0).
See the raylib and raylib-extras repositories for their respective licenses.
