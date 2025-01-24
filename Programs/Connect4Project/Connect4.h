#ifndef CONNECT4_H
#define CONNECT4_H
#include <vector>
#include <string>
#include <utility>

enum GameState {
  PLAYING,
  DRAW,
  WIN,
};




struct Connect4{
  int rows;
  int cols;

  std::vector<std::vector<char>> Board;

  const char Player1 = 'X';
  const char Player2 = 'O';
  const char Empty = ' ';

  const int MaxMoves = 42;

  bool PlayerOneTurn;

  bool Win;

  int PlayersMove;

  int Height;

  int Moves;

  int WinCount;

  std::pair<int,int> rows_cols;

  Connect4();
  Connect4(std::vector<std::vector<char>> Board);

  void Display();

  std::string to_string();

  void WinLogic();

  void update(int col);

  std::string MakeMove();

  int CountHeight(int PlayersMove);

  bool InIndex(int, int);

  void InColumn();

  void InRow();
  void CheckLeft();
  void CheckRight();

  int MakeMoveInColumnTest();

  int MakeMoveInRowTest();

};





#endif
