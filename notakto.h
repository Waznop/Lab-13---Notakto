/** Header file for notakto.cpp. Do not alter this file.
@file notakto.h
@author Hong Tai Wei
*/

#ifndef NOTAKTO_H
#define NOTAKTO_H

// Given a notakto board as a 2D bool array, draw it out to standard output.
void draw_board(const bool board[3][3]);

// Given a notakto board as a 2D bool array, return whether it has a line of 3
// X's (true's).
bool has_line(const bool board[3][3]);

// Place an X (true) on the notakto board at the given index, then return true.
// If the index is invalid, return false.
// If the board already contains an X (true) at that index, return false.
bool place_x(bool board[3][3], int idx);

#endif  // MARKET_H