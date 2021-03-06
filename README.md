# Lab 13: Notakto

In this lab, you will learn how to:
- write an executable program from scratch.

You will write a series of functions for the Notakto game, test them using the GoogleTest framework, then call them in a driver program.

## File structure

* `Makefile` - Configuration for `make`.
* `main.cpp` - Your main function goes here.
* `notakto.cpp` - Your Notakto related functions go here.
* `notakto_test.cpp` - Your tests go here.
* `notakto.h` - Header file for `notakto.cpp`, already written for you.
* `notakto_complete` - An executable demo generated by a correct implementation.
* `googletest/` - Contains code for the GoogleTest framework.

**Do not change any files other than `main.cpp`, `notakto.cpp` and `notakto_test.cpp`!**

## Make commands

You have the same `make` commands (format, build, test, all, clean) as usual.

## Program specifications

[Notakto](https://en.wikipedia.org/wiki/Notakto) is a Tic-Tac-Toe variant where:
* Instead of X's and O's, both players put down X's.
* Instead of winning, the player who forms a line loses.

Here's a summary of the rules:
* 2 players play on a 3x3 board.
* On your turn, find an empty slot on the board to put down an X.
* If a line of 3 X's is formed as a result (horizontal, vertical or diagonal), you lose.
* Otherwise, it's the other player's turn.

You can play a complete version of Notakto in the terminal by running `./notakto_complete`.

### The game board

`bool board[3][3]`

The board is represented by a 3 by 3 array of booleans. A true means there's an X, a false means it's an empty slot.

Eg. `{{1, 0, 1}, {0, 1, 0}, {0, 0, 0}}` represents a board that looks like this:
```
-------------
| 1 | 2 | 3 |
| X |   | X |
-------------
| 4 | 5 | 6 |
|   | X |   |
-------------
| 7 | 8 | 9 |
|   |   |   |
-------------
```

When placing an X, an index from 1 to 9 specifies the desired slot, as shown above.

Eg. an index of `1` represents the slot `board[0][0]`, an index of `6` represents the slot `board[1][2]`.

## Part 1

For part 1, complete the unit tests, then implement the functions that you will call in your program in part 2.

### 1.1 `draw_board()`

```c++
void draw_board(const bool board[3][3]);
```

Given a Notakto board, print it out onto the terminal.

Eg.
```c++
bool board[3][3] = {{1, 0, 1}, {0, 1, 0}, {0, 0, 0}};
draw_board(board);
/*
the following pattern should now be printed onto the terminal:
-------------
| 1 | 2 | 3 |
| X |   | X |
-------------
| 4 | 5 | 6 |
|   | X |   |
-------------
| 7 | 8 | 9 |
|   |   |   |
-------------
*/
```

**TODO**: Complete the test case in `TEST(NotaktoTest, DrawBoard1)`.
- Fill in the board.
- Fill in the expected output onto the terminal.

**TODO**: Copy the above test case to have at least 3 test cases total. Don't forget to rename the copied cases (DrawBoard2, DrawBoard3, ...).

**TODO**: Complete the implementation for `draw_board()` and test it using `make test`.

### 1.2 `has_line()`

```c++
bool has_line(const bool board[3][3]);
```

Given a Notakto board, return whether it has a line of 3 X's (true's).

Eg.
```c++
bool board1[3][3] = {{1, 0, 1}, {0, 1, 0}, {0, 0, 0}};
// this is the board from the previous example with X's at slots 1, 3, 5
has_line(board1); // false, there isn't a line of 3 X's

bool board2[3][3] = {{1, 0, 1}, {0, 1, 0}, {0, 0, 1}};
// this board has an X at slots 1, 3, 5, 9
has_line(board2); // true, slots 1, 5, 9 form a diagonal line of 3 X's
```

**TODO**: Complete the test case in `TEST(NotaktoTest, HasLine1)`.
- Fill in the board.
- Fill in the expected return value of the `has_line()` function.

**TODO**: Copy the above test case to have at least 3 test cases total. Don't forget to rename the copied cases (HasLine2, HasLine3, ...).

**TODO**: Complete the implementation for `has_line()` and test it using `make test`.

### 1.3 `place_x()`

```c++
bool place_x(bool board[3][3], int idx);
```

Place an X (true) on the Notakto board at the given index.
* If the index is invalid (not between 1 and 9 inclusively), return false.
* If the board already contains an X (true) at that index, return false.
* Otherwise, modify the board to have an X (true) at that index, then return true.

Eg.
```c++
bool board[3][3] = {{1, 0, 1}, {0, 1, 0}, {0, 0, 0}};
place_x(board, 0); // false, index 0 is invalid
place_x(board, 1); // false, index 1 (board[0][0]) already has an X
place_x(board, 2); // true, index 2 (board[0][1]) was empty
// now board should have value {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}}
```

**TODO**: Complete the test case in `TEST(NotaktoTest, PlaceX1)`.
- Fill in the board's starting state.
- Fill in the index to place an X (true) at.
- Fill in the expected return value of the `place_x()` function.
- Fill in the expected board after calling `place_x()`.

**TODO**: Copy the above test case to have at least 3 test cases total. Don't forget to rename the copied cases (PlaceX2, PlaceX3, ...).

**TODO**: Complete the implementation for `place_x()` and test it using `make test`.

## Part 2

Now that you're done with implementing `draw_board()`, `has_line()` and `place_x()`, put together a Notakto program by calling them in `main()` in `main.cpp`. If you do it correctly, the `./notakto` program that gets built from running `make build` should behave exactly the same way as the provided `./notakto_complete` program.

Your program should:

1. Draw the board using `draw_board()`.
2. Print out `"Player 1's turn (Enter a location to place X):"` + newline.
3. Wait for the user to input an index, then call `place_x()` with it.
4. If `place_x()` returns false, print out `"Location invalid or already taken. Please try again."` + newline and go back to step 3.
5. Otherwise, call `has_line()` with the modified board.
6. If `has_line()` returns true, Player 1 (the current player) loses, so draw the board then print out `"Player 2 wins!"` + newline before ending the program.
7. Otherwise, go back to step 1, but this time for the other player (swap Player 1 with Player 2 in all the steps).

An example terminal playthrough could look like this:
```
$ ./notakto_complete 
-------------
| 1 | 2 | 3 |
|   |   |   |
-------------
| 4 | 5 | 6 |
|   |   |   |
-------------
| 7 | 8 | 9 |
|   |   |   |
-------------
Player 1's turn (Enter a location to place X):
1
-------------
| 1 | 2 | 3 |
| X |   |   |
-------------
| 4 | 5 | 6 |
|   |   |   |
-------------
| 7 | 8 | 9 |
|   |   |   |
-------------
Player 2's turn (Enter a location to place X):
5
-------------
| 1 | 2 | 3 |
| X |   |   |
-------------
| 4 | 5 | 6 |
|   | X |   |
-------------
| 7 | 8 | 9 |
|   |   |   |
-------------
Player 1's turn (Enter a location to place X):
4
-------------
| 1 | 2 | 3 |
| X |   |   |
-------------
| 4 | 5 | 6 |
| X | X |   |
-------------
| 7 | 8 | 9 |
|   |   |   |
-------------
Player 2's turn (Enter a location to place X):
7
-------------
| 1 | 2 | 3 |
| X |   |   |
-------------
| 4 | 5 | 6 |
| X | X |   |
-------------
| 7 | 8 | 9 |
| X |   |   |
-------------
Player 1 wins! 
```

## Rubric

* (60 points) Programming
  * (1.5 points) TODO comment check
  * (1.5 points) Style check
  * (37 points) Autograder test cases for `notakto.cpp`
  * (10 points) Good test cases in `notakto_test.cpp`
  * (10 points) Good program design in `main.cpp`
* (40 points) Written assignment ??? see Gradescope for point breakdowns

## Due Date

- Section A: November 30, 11:59pm
- Section B: December 2, 11:59pm

See [bit.ly/hwei-cs120-info](https://bit.ly/hwei-cs120-info) for all due dates.
