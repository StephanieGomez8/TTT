// Copyright 2018 Stephanie Gomez sagomez@bu.edu
#include <iostream>
#include <string>
#include <vector>
#include "movedef.h"
using std::cout;
using std::string;
using std::vector;
int numbt, numbo, numbx, numbi, numbc;
int xcount, ocount;
vector<string> get_all_boards() {
  vector<string> out;
  char symbols[] = {'#', 'o', 'x'};
  string s("#########");
  for (int a = 0; a < 196823; a++) {
    int n = a;
    for (int b = 0; b < 9; b++) {
      int d = n % 3;
      n = n / 3;
      s[b] = symbols[d];
    }
    out.push_back(s);
  }
  return out;
}
// Creating a MultiDimensional Array
char tttresult(string tttboard) {
// creating board
  int n;
  int i;
  int j;
  int xcount = 0;
  int ocount = 0;
  char tttboards[3][3];
  if (tttboard.length() != 9) {
    return 'e';
  }
  for (int i = 0; i < 3 ; i++) {
    for (int j = 0; j < 3; j++) {
      n = (i * 3 + j);
      tttboards[i][j] = tttboard[n];
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
      // checking if there are o,x,#
      if (tttboard[n] != 'o' && tttboard[n] != 'x' && tttboard[n] != '#') {
        return 'e';
      }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
      // error checking for more o and x counts
      if (tttboard[n] == 'x') {
        xcount++;
      } else if (tttboard[n] == 'o') {
        ocount++;
      }
    }
  }
  if (ocount > xcount || xcount > ocount + 1) {
    numbi++;
    return 'i';
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Check to make sure game keeps going
  if (xcount + ocount <= 8 && tttboard[n] == '#') {
    numbc++;
    return 'c';
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // checking vertical x wins
  if (tttboards[0][0] == 'x' && tttboards[1][0] == 'x' &&
      tttboards[2][0] == 'x') {
    numbx++;
    return 'x';
  }

  if (tttboards[0][1] == 'x' && tttboards[1][1] == 'x' &&
      tttboards[2][1] == 'x') {
    numbx++;
    return 'x';
  }
  if (tttboards[0][2] == 'x' && tttboards[1][2] == 'x' &&
      tttboards[2][2] == 'x') {
    numbx++;
    return 'x';
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Checking horizontal x wins
  if (tttboards[0][0] == 'x' && tttboards[0][1] == 'x' &&
      tttboards[0][2] == 'x') {
    numbx++;
    return 'x';
  }
  if (tttboards[1][0] == 'x' && tttboards[1][1] == 'x'
      && tttboards[1][2] == 'x') {
    numbx++;
    return 'x';
  }
  if (tttboards[2][0] == 'x' && tttboards[2][1] == 'x' &&
      tttboards[2][2] == 'x') {
    numbx++;
    return 'x';
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Checking diagonal x wins
  if (tttboards[0][0] == 'x' && tttboards[1][1] == 'x' &&
      tttboards[2][2] == 'x') {
    numbx++;
    return 'x';
  }
  if (tttboards[0][2] == 'x' && tttboards[1][1] == 'x' &&
      tttboards[2][0] == 'x') {
    numbx++;
    return 'x';
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // checking vertical o wins
  if (tttboards[0][0] == 'o' && tttboards[1][0] == 'o' &&
      tttboards[2][0] == 'o') {
    numbo++;
    return 'o';
  }
  if (tttboards[0][1] == 'o' && tttboards[1][1] == 'o' &&
      tttboards[2][1] == 'o') {
    numbo++;
    return 'o';
  }
  if (tttboards[0][2] == 'o' && tttboards[1][2] == 'o' &&
      tttboards[2][2] == 'o') {
    numbo++;
    return 'o';
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Checking horizontal o wins
  if (tttboards[0][0] == 'o' && tttboards[0][1] == 'o' &&
      tttboards[0][2] == 'o') {
    numbo++;
    return 'o';
  }
  if (tttboards[1][0] == 'o' && tttboards[1][1] == 'o' &&
      tttboards[1][2] == 'o') {
    numbo++;
    return 'o';
  }
  if (tttboards[2][0] == 'o' && tttboards[2][1] == 'o' &&
      tttboards[2][2] == 'o') {
    numbo++;
    return 'o';
  }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Checking vertical o wins
  if (tttboards[0][0] == 'o' && tttboards[1][1] == 'o' &&
      tttboards[2][2] == 'o') {
    numbo++;
    return 'o';
  }
  if (tttboards[0][2] == 'o' && tttboards[1][1] == 'o' &&
      tttboards[2][0] == 'o') {
    numbo++;
    return 'o';
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Check the game for tie
  if (xcount == 5 && ocount == 4) {
    numbt++;
    return 't';
  }
}
char tttresult(vector<Move> board) {
  string tttboard = "#########";
  if (board.size() > 9) {
    return 'e';
  }
  for (int m = 0; m < board.size(); m++) {
    if (board[m].r > 2 || board[m].c > 2) {
      numbi++;
      return 'e';
    }
    int location = (3 * board[m].r) + board[m].c;
    if (tttboard[location] == 'x' || tttboard[location] == 'o') {
      return 'e';
    }
    tttboard.replace(location, 1, 1, board[m].player);
  }
  char result = tttresult(tttboard);
  return result;
}
// MAIN
int main() {
  std::vector<Move> moves;
  std::vector<string> test;
  test = get_all_boards();
  for (int i = 0; i < test.size(); i++) {
    ocount = 0;
    xcount = 0;
    tttresult(test.at(i));
  }
  cout << "t " << numbt << '\n' << "o " << numbo << '\n';
  cout << "x " << numbx << '\n' << "i " << numbi << '\n';
  cout << "c " << numbc << '\n';
  return 0;
}
