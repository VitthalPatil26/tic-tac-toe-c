# Tic-Tac-Toe in C

A two-player, console-based Tic-Tac-Toe game written in C. Players enter their names, take turns marking a 3x3 board, and can replay as many rounds as they like.

## Features

- Two players with custom names (Player 1 = `X`, Player 2 = `O`)
- Numbered board (1 to 9) so moves are easy to pick
- Input validation for out-of-range positions
- Detection of already-occupied cells
- Win detection across all 8 combinations (3 rows, 3 columns, 2 diagonals)
- Draw detection after 9 valid moves
- Replay option without restarting the program

## Sample Gameplay

```text
Enter v position[X] : 5
|---|---|---|
| X | 2 | 3 |
|---|---|---|
| O | X | 6 |
|---|---|---|
| 7 | 8 | 9 |
|---|---|---|

Enter b position[O] : 2
|---|---|---|
| X | O | 3 |
|---|---|---|
| O | X | 6 |
|---|---|---|
| 7 | 8 | 9 |
|---|---|---|

Enter v position[X] : 9
|---|---|---|
| X | O | 3 |
|---|---|---|
| O | X | 6 |
|---|---|---|
| 7 | 8 | X |
|---|---|---|
Congrats v!. You won

Do you want to play again (Y/N) : n

Thank you for playing
```

## Getting Started

### Prerequisites

- A C compiler such as `gcc`

### Compile

```bash
gcc -Wall -Wextra tic_tac_toe.c -o tic_tac_toe
```

### Run

```bash
./tic_tac_toe
```

## How to Play

1. Enter `Y` to start the game.
2. Enter the names of Player 1 and Player 2.
3. On your turn, type a number from 1 to 9 to place your mark in that cell.
4. The first player to get three marks in a row, column, or diagonal wins.
5. If all 9 cells are filled with no winner, the game is a draw.
6. After each game, choose `Y` to play again or `N` to exit.

## How It Works

| Part | Description |
|------|-------------|
| `board[9]` | A `char` array holding `'1'` to `'9'` initially, replaced by `'X'` or `'O'` as moves are made |
| `turn` | Tracks whose turn it is (1 = Player 1, 2 = Player 2) |
| `moves` | Counts valid moves; reaching 9 without a winner means a draw |
| `check_winner()` | Compares the 8 winning index combinations and returns 1 if a line matches |
| `display_board()` | Prints the current board state |
| Outer `do-while` loop | Lets players start a new game and resets the board |

## Concepts Used

- Arrays and character handling
- Functions and modular design
- Loops and control flow (`while`, `do-while`, `break`)
- Console input with `scanf` and basic input validation
- Game state management (turns, move count, reset)

## Possible Improvements

- Handle non-numeric input without re-prompting endlessly
- Limit name length safely with a width specifier in `scanf`
- Merge the two player-turn blocks into one using a symbol variable
- Add a score tracker across multiple rounds
- Add a single-player mode against a simple computer opponent

## Author

Vittal
