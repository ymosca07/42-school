*This project has been created as part of the 42 curriculum by yamosca-.*

# Napolong

## Description

**Napolong** is a small 2D game project developed using the MinilibX library. It challenges you to create a simple graphical application involving texture rendering, event handling, and basic game mechanics.

In this implementation, the player controls **Napoleon**. The primary goal is to collect all scattered **territories** (collectibles) on the map. Only after reconquering all territories can the player reach **Josephine** (the exit) to complete the level.

This project focuses on:

* **Window Management**: Handling opening, closing, and minimizing windows smoothly.
* **Event Handling**: managing keyboard inputs (WASD) and window events.
* **Map Parsing**: Validating map structure (.ber files) and checking valid paths using Flood Fill algorithms.
* **Texture Rendering**: Displaying XPM images efficiently.

### Controls

Once the window is open, use the following keys to control Napoleon:

    W : Move Up

    A : Move Left

    S : Move Down

    D : Move Right

    ESC / ❌ : Close the game

### Compilation

Clone the repository and compile the executable using the Makefile:

make

### Example Output

While the game is running graphically, the shell displays the number of movements:

Step's counter: 1
Step's counter: 2
Step's counter: 3
...

### Norminette

To verify the code norm quality while excluding the MinilibX library (which is not norm-compliant), use the following command:

**norminette $(find . -name "*.[ch]" -not -path "./minilibx/*")**