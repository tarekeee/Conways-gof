# Conway's Game of Life in C++ with SFML

## Overview

This repository contains a C++ implementation of Conway's Game of Life using the SFML library. The game has two modes: drawing and simulation.

## Modes

In drawing mode, you can click on the grid to place or remove live cells. To switch to simulation mode, press the Enter key.

In simulation mode, the game will automatically evolve based on the following rules:

    Any live cell with two or three live neighbors survives.
    Any dead cell with three live neighbors becomes a live cell.
    All other live cells die in the next generation.
    Similarly, all other dead cells stay dead.

## Running the game

To run the game, open a terminal and navigate to the root directory of the repository. Then, run the following command:

```
make && ./output <fps>
```

The default FPS is 15, but you can specify a different value by passing it to the output executable.

## Controls

    Enter: Switch between drawing and simulation modes.

## Example

To run the game at 30 FPS, you would run the following command:

```
make && ./output 30
```

This will open a window with a grid where you can draw or simulate the Game of Life. You can switch between modes by pressing the Enter key.

## Contributing

If you would like to contribute to this project, please feel free to open a pull request. All contributions are welcome!