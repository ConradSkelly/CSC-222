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

  Connect4();

  void Display();
  std::string to_string();

  Connect4(std::vector<std::vector<char>> Board);
  void update(int col);

};





#endif
