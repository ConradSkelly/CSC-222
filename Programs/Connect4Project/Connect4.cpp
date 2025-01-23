#include "Connect4.h"
#include <vector>
#include <iostream>
#include <string>

Connect4::Connect4(){
  rows = 6;
  cols = 7;
  Board = std::vector<std::vector<char> >(rows, std::vector<char>(cols, Empty));

  PlayerOneTurn = true;
  PlayersMove = 0;

  Height = 0;
}

Connect4::Connect4(std::vector<std::vector<char>> Board){
  rows = 7;
  cols = 6;

  this->Board = Board;
  PlayerOneTurn = true;
  PlayersMove = 0;
  Height = 0;

}

std::string Connect4::to_string( ){
  std::string output = "";
  for (int row = 0; row < rows; row++){
    for (int col = 0; col < cols; col++){
      output.push_back((Board[row][col]));
      std::cout << Board[row][col];
    }
      output += "\n";
      std::cout << "\n";
  }
  return output;
}

std::string Connect4::MakeMove(){
  if (PlayerOneTurn){
    PlayerOneTurn = false;

    do{
    std::cout << "enter a interger from 1 to 7: ";
    std::cin >> PlayersMove;
    int Height = Connect4::CountHeight(PlayersMove);
    } while (Height >= rows);
    std::cout << PlayersMove-1 << std::endl;
    std::cout << Height << std::endl;
    Board[Height][PlayersMove-1] = Player1;
    std::cout << Board[Height][PlayersMove-1] << std::endl;
  }

  else{
    PlayerOneTurn = true;

    do{
    std::cout << "enter a interger from 1 to 7: ";
    std::cin >> PlayersMove;
    int Height = Connect4::CountHeight(PlayersMove);
    } while (Height >= rows);
  }

  return to_string();
}

int Connect4::CountHeight(int PlayersMove){
  int count = 0;
  for (int row = 0; row < rows; row++){
    if (Board[row][PlayersMove-1] == Player1 or Board[row][PlayersMove-1] == Player2)
      count++;
  }
  return count;
}




