#  Advanced Number Guessing Game c

## About

This is an advanced console-based Number Guessing Game written in C as a practice project while learning the C programming language.

Unlike a basic guessing game, this version includes multiple difficulty levels, hot/cold feedback, input validation, replay functionality, and a special Insanity mode with limited attempts.

---

## Features

-  Four difficulty levels
  - Easy (1–50)
  - Medium (1–100)
  - Hard (1–500)
  - Insanity Mode (1–500 with only 10 attempts)

-  Hot/Cold feedback based on how close your guess is.

-  Input validation for invalid difficulty selection.

-  Out-of-range detection.

-  Play Again option.

-  Random number generation using `rand()` and `time()`.

-  Counts the number of guesses taken to win.

---

## Concepts Used

- Variables
- Functions
- `if-else` statements
- `do-while` loops
- `goto`
- Random Number Generation (`rand()`, `srand()`)
- Standard Libraries
  - `stdio.h`
  - `stdlib.h`
  - `time.h`

---

## How to Run

Compile the program:

```bash
gcc Advanced_Number_Guessing_Game.c -o game
```

Run the executable:

### Windows

```bash
game.exe
```

### Linux / macOS

```bash
./game
```

---

## Sample Gameplay

```
Welcome to the World of Guessing Numbers

Choose Difficulty

1. Easy
2. Medium
3. Hard
4. Insanity

Guess a number between 1 and 100.

50
You're getting warmer...

Larger number please...

72
Very close...

Smaller number please...

68
Congratulations!!!
You guessed the number in 3 attempts.
```

## Author

**Krish Kumar**

Learning C programming by building small projects.
