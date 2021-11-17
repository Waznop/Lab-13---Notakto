/** Test cases for functions defined in notakto.h
@file notakto_test.cpp
@author YOUR NAME HERE
*/
// TODO: Fill in your name above.

#include "notakto.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;
using ::testing::internal::CaptureStdout;
using ::testing::internal::GetCapturedStdout;

string format_output(const string& output);
void EXPECT_ARRAY_EQ(const bool actual[3][3], const bool expected[3][3]);

// DO NOT MODIFY CODE ABOVE

// TODO: Copy the code below to have at least 3 test cases total.
// Don't forget to rename the copied cases (DrawBoard2, DrawBoard3, ...)
TEST(NotaktoTest, DrawBoard1) {
  // TODO: Fill the board.
  bool board[3][3] = {};

  // TODO: Modify the expected output depending on your board.
  string expected_output = R"(
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
  )";

  // Don't modify the next 3 lines, but don't forget to copy them.
  CaptureStdout();
  draw_board(board);
  EXPECT_EQ(GetCapturedStdout(), format_output(expected_output));
}

// TODO: Copy the code below to have at least 3 test cases total.
// Don't forget to rename the copied cases (HasLine2, HasLine3, ...)
TEST(NotaktoTest, HasLine1) {
  // TODO: Fill the board and the expected answer.
  bool board[3][3] = {};
  bool expected_answer = false;

  // Don't modify the next line.
  EXPECT_EQ(has_line(board), expected_answer);
}

// TODO: Copy the code below to have at least 3 test cases total.
// Don't forget to rename the copied cases (PlaceX2, PlaceX3, ...)
TEST(NotaktoTest, PlaceX1) {
  // TODO: Fill the board's starting state, the index to place at, the expected
  // answer and the expected board state after the placement.
  bool board[3][3] = {};
  int idx = -1;
  bool expected_answer = false;
  bool expected_board[3][3] = {};

  // Don't modify the next 2 lines.
  EXPECT_EQ(place_x(board, idx), expected_answer);
  EXPECT_ARRAY_EQ(board, expected_board);
}

// DO NOT MODIFY CODE BELOW

string format_output(const string& output) {
  string out;
  bool skipping = false;
  for (char ch : output) {
    if (skipping) {
      if (ch == ' ') {
        continue;
      }
      skipping = false;
    } else if (ch == '\n') {
      skipping = true;
    }
    out += ch;
  }
  if (out[0] == '\n') {
    out.erase(0, 1);
  }
  return out;
}

void EXPECT_ARRAY_EQ(const bool actual[3][3], const bool expected[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_EQ(actual[i][j], expected[i][j])
          << "Actual and expected differ at index i = " << i << ", j = " << j;
    }
  }
}