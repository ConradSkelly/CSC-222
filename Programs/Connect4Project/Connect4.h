#ifndef CONNECT4_H
#define CONNECT4_H
#include <vector>
#include <string>

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

  bool PlayerOneTurn;

  int PlayersMove;

  int Height = 0;

  Connect4();
  Connect4(std::vector<std::vector<char>> Board);

  void Display();

  std::string to_string();

  bool CheckWin();

  void update(int col);

  std::string MakeMove();

  int CountHeight(int PlayersMove);

};





#endif
