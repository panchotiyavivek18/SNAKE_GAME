# Snake Game (C++)

This is a simple console-based Snake Game written in C++. The game allows you to control a snake to eat food while avoiding collisions with the boundaries and its own body. You can adjust the speed of the game and restart it after losing.

## Features

- Adjustable game speed
- Collision detection (walls and self)
- Score tracking
- Restart option after game over
- Simple and engaging gameplay

## Requirements

- C++ compiler (such as GCC or MSVC)
- Windows operating system (for `conio.h` and `windows.h` usage)
  
## How to Compile and Run

1. Ensure you have a C++ compiler installed (e.g., GCC or MSVC).
2. Download or copy the `snake_game.cpp` file to your system.
3. Open your terminal or command prompt and navigate to the directory where the file is saved.
4. Compile the code:

    For GCC:
    ```bash
    g++ snake_game.cpp -o snake_game
    ```

    For MSVC:
    ```bash
    cl snake_game.cpp
    ```

5. Run the executable:
   
    For GCC:
    ```bash
    ./snake_game
    ```

    For MSVC:
    ```bash
    snake_game.exe
    ```

6. Start the game by typing 'YES' when prompted to play the Snake Game.

## Gameplay Instructions

- **Controls**:
  - Arrow keys to move (Up, Down, Left, Right)
  - Press '0' to quit the game
  - When the game ends, type 'R' to restart or any other key to exit

- **Game Objective**: 
  - Eat food (denoted by 'F') to grow the snake.
  - Avoid running into walls or your own body.
  - The game ends when you hit a wall or collide with yourself.

## Customization

- **Speed**: You can adjust the game speed by changing the value of `gameSpeed` in the `main()` function. The speed is measured in milliseconds, where a lower value results in faster gameplay.

```cpp
int gameSpeed = 200; // Adjust to change the speed of the game (in ms)
```
### Changes made:

- **Grid Size**: Added a section to explain how users can adjust the grid size using `gridWidth` and `gridHeight`.
- **Greetings**: Explained the initial greeting prompt when the user starts the game.

