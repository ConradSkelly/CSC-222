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

  std::string Display;

  int PlayerInput;

  bool PlayerOneTurn;

  bool Win;

  int PlayersMove;

  int Height;

  int Moves;

  int WinCount;

  int WinDiagonalBottomToTop;
  int WinDiagonalTopToBottom;


  std::pair<int,int> rows_cols;

  Connect4();
  Connect4(std::vector<std::vector<char>> Board);
  Connect4(std::vector<std::vector<char>> Board, int PlayerInput);

  std::string to_string();

  void WinLogic();

  void update(int col);

  int MakeMove();

  int CountHeight(int PlayersMove);

  bool InIndex(int, int);

  int  InColumn();

  int  InRow();
  void CheckLeft();
  void CheckRight();

  int InDiagonal();

  void CheckDiagonalBottomToTop();
  void CheckDiagonalBottomToTopLeft();
  void CheckDiagonalBottomToTopRight();

  void CheckDiagonalTopToBottom();
  void CheckDiagonalTopToBottomLeft();
  void CheckDiagonalTopToBottomRight();

  int MakeMoveInColumnTest();

  int MakeMoveInRowTest();

  int MakeMoveInDiagonalTest();

  std::string MakeMoveDisplayTest();

  int RunGame();

};





#endif
