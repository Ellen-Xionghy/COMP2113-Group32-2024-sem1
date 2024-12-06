# COMP2113-Group32-2024-sem1
# Team Members
- Shi Songen 
- Xiong Hanyi
- Wang Ching Hoi

# Game Introduction

## Name
Welcome to this exciting Airplane Chess board game! In this game, players will move across a map filled with various squares by rolling dice. Each square has different effects that can bring good luck or misfortune. With strategy and a bit of luck, race to be the first to reach the finish line and claim victory! Whether playing with friends or family, the fun is endless—come challenge yourself!

## START GAME
To start the game, you have four options:
1. Type "1" to start a new game.
2. Type "2" to view the previous winner list.
3. Type "3" to read the rules.
4. Type "4" to quit the game.

## GAME SET UP
1. **Starting a New Game**
   - First, you need to input the number of players.  
   **Note**: The number must be between 2-4; if it is out of this range, you will receive a warning and should input a valid number again.
   
2. **Input Player Names**
   - Next, input the names of the players in order.  
   **Note**: Names must be non-empty and distinct; otherwise, you should input valid names again.
   
3. **View the Game Map**
   - You will see the map along with player names, where various squares are displayed. Here’s what the different types of squares represent: 
     - **"#"**: Normal square, no special effects.
     - **"+"**: Lucky square. When a player lands on it, they will receive a bonus, which is a random integer from 1 to 10, allowing them to move forward that many steps.
     - **"@"**: Unlucky square. When a player lands on it, they will incur a penalty, which is a random integer from 1 to 3, causing them to move back that many steps.
     - **"*"**: Pause square. When a player lands on it, they must pause for one round and can move in the next round.
     - **"%"**: Swap square. When a player lands on it, they will swap positions with another random player.
     - **"&"**: Indicates multiple players standing on the same square.
     - **Player Index**: If only one player is on a square, their index will represent them.

## GAME PROCESS
1. At the start, every player is on the first square.
2. Each player rolls dice in order.  
   You should type "c" to roll the dice or "q" to quit the game. Other inputs will be considered invalid, and you'll need to input it again.
3. Next, you will see how many steps you will move, and your move will be shown on the map. Then, the next player will roll the dice.
4. Interestingly, when a player moves to a position occupied by another player, the player who arrives later will move back 3 squares.
5. When a player is close to the finish line (e.g., 3 squares away), they must roll a 3 to reach the destination; otherwise, they will move back. If the dice show 5, they will be 2 squares away from the destination.

## FINISHING GAME
1. When a player reaches the finish line, the game will end in that round.
2. The winner will be recorded and stored.

# Game Technical Features

1. **Generation of Random Game Events**
   - **Player Movement Points**: The number of steps a player advances is determined by a random dice roll, generating an unpredictable gameplay experience.
   - **Random Player Swapping**: When a player lands on a swap square, the player they exchange positions with is randomly selected from the other players, adding an element of surprise.

2. **Data Structures for Storing Game Status**
   - **Vector and Array**: The game utilizes both vectors and arrays to store player positions, names, and other relevant game data, allowing for efficient management and access to game states.

3. **Dynamic Memory Management**
   - After a player wins, dynamic memory is used to insert the winner into the existing winner list in ascending order based on their score. This ensures that the winner list is always sorted.

4. **File Input/Output**
   - **Input**: The game reads rules and the previous winner list from input files, ensuring players are informed about the game's objectives and past performance.
   - **Output**: After updating the winner list, the new data is output to `record.txt`, allowing for persistent storage of game results.

5. **Program Codes in Multiple Files**
   - The project is organized into several files:
     - `main.cpp`: Contains the main game logic and entry point.
     - `main.h`: Header file for main program declarations.
     - `drawmap.cpp` and `drawmap.h`: Handle the display of the game map.
     - `functions.cpp` and `functions.h`: Contain various game functions for player actions and game mechanics.

# Video link
   - https://youtu.be/F_2GEyPH6Dc


# Compilation Instructions
To compile and run the game program, use the following commands:

```bash
make clean  
make         
./my_program.exe


