#include "Connect4.h"
#include <vector>
#include <iostream>
#include <string>

Connect4::Connect4(){
  rows = 7;
  cols = 6;
  Board = std::vector<std::vector<char> >(rows, std::vector<char>(cols, Empty));

  bool PlayerOneTurn = true;
  int PlayersMove;
}

Connect4::Connect4(std::vector<std::vector<char>> Board){
  rows = 7;
  cols = 6;

  this->Board = Board;

}

std::string Connect4::to_string( ){
  std::string output = "";

  for (int row = 0; row < rows; row++){
    for (int col = 0; col < cols; col++){
      output.push_back((Board[row][col]));
    }
      output += "\n";
  }
  return output;
}

void Connect4::MakeMove(bool PlayerOneTurn){
  if (PlayerOneTurn){
    PlayerOneTurn = false;

    do{
    std::cout << "enter a interger from 1 to 7: ";
    std::cin >> PlayersMove;
    int Height = Connect4::CountHeight(PlayersMove);
    } while (Height == 7);

    Board[Height][PlayersMove-1] = Player1;
  }

  else{
    PlayerOneTurn = true;

    do{
    std::cout << "enter a interger from 1 to 7: ";
    std::cin >> PlayersMove;
    int Height = Connect4::CountHeight(PlayersMove);
    } while (Height == 7);

    Board[PlayersMove-1][Height] = Player2;
  }
}

int Connect4::CountHeight(int PlayersMove){
  int count = 0;
  for (int col = 0; col < cols; col++){
    if (Board[col][PlayersMove-1] == Player1 or Board[col][PlayersMove-1] == Player2)
      count++;
  }
  return count;
}




