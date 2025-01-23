#include "Connect4.h"
#include <vector>
#include <iostream>
#include <string>

Connect4::Connect4(){
  rows = 7;
  cols = 6;

  Board = std::vector<std::vector<char> >(rows, std::vector<char>(cols, Empty));
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

