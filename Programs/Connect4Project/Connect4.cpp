#include "Connect4.h"
#include <vector>
#include <iostream>
#include <string>
#include <utility>

Connect4::Connect4(){
  rows = 6;
  cols = 7;
  Board = std::vector<std::vector<char> >(rows, std::vector<char>(cols, Empty));

  PlayerOneTurn = true;
  PlayersMove = 0;

  Height = 0;
}

Connect4::Connect4(std::vector<std::vector<char>> Board){
  rows = 6;
  cols = 7;

  this->Board = Board;
  PlayerOneTurn = true;
  PlayersMove = 0;
  Height = 0;
  Moves = 0;
  rows_cols = std::make_pair(0, 0);
  WinCount = 0;
  Win = 0;

  std::cout << "this is the board stat in the start";
  for(int row = 0; row < rows; row++){
    for(int col = 0; col < cols; col++){
      std::cout << Board[row][col];
    }
    std::cout << std::endl;
  }

  if (Board[5][0] == 'O')
    std::cout << "they are equal \n ";

}

std::string Connect4::to_string( ){
  std::string output = "\n";
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
    Height = Connect4::CountHeight(PlayersMove);
    } while (Height >= rows);
    rows_cols = std::make_pair(-Height+5,PlayersMove-1);
    Board[-Height + 5][PlayersMove-1] = Player1;
  }

  else{
    PlayerOneTurn = true;

    do{
    std::cout << "enter a interger from 1 to 7: ";
    std::cin >> PlayersMove;
    Height = Connect4::CountHeight(PlayersMove);
    } while (Height >= rows);
    rows_cols = std::make_pair(-Height+5,PlayersMove-1);
    Board[-Height+5][PlayersMove-1] = Player2;
  }
  Moves++;
  return to_string();
}

void Connect4::WinLogic(){
// check Column

}

int Connect4::CountHeight(int PlayersMove){
  int count = 0;
  for (int row = 0; row < rows; row++){
    if (Board[row][PlayersMove-1] == 'X' or Board[row][PlayersMove-1] == 'O')
      count++;
  }
  return count;
}

bool Connect4::InIndex(int Rows, int Cols){
  std::cout << Rows << " " << Cols << std::endl;
  return !(Rows> 5 or Rows < 0 or Cols < 0 or Cols > 6);
}

void Connect4::InColumn(){
  if (!PlayerOneTurn){
  for (int i = 0; i < 4; i++){
    if (InIndex(rows_cols.first, rows_cols.second+i)){
      if (Board[rows_cols.first+i][rows_cols.second] == 'X')
        WinCount++;
      }
    else{
      WinCount = 0;
      break;
      }
  }
   Win = (WinCount >= 4);
   WinCount = 0;
  }

  else{
      for (int i = 0; i < 4; i++){
    if (InIndex(rows_cols.first, rows_cols.second+i)){
      if (Board[rows_cols.first+i][rows_cols.second] == 'O')
        WinCount++;
      }
    else{
      WinCount = 0;
      break;
      }
  }
   Win = (WinCount >= 4);
   WinCount = 0;
  }
}

void Connect4::InRow(){
  std::cout << WinCount << std::endl;
  CheckLeft();
  std::cout << WinCount << std::endl;
  CheckRight();
  std::cout << WinCount << std::endl;
  Win = (WinCount >= 4);
  WinCount = 0;
}

void Connect4::CheckLeft(){
  for (int i = 0; i < 4; i = i+1){
    if (InIndex(rows_cols.first, rows_cols.second-i)){
      if (Board[rows_cols.first][rows_cols.second-i] == 'X')
        WinCount++;
      else
        break;
      }
    }
  }

void Connect4::CheckRight(){
  for (int i = 1; i < 4; i = i+1){
    if (InIndex(rows_cols.first, rows_cols.second+i)){
      if (Board[rows_cols.first][rows_cols.second+i] == 'X')
        WinCount++;
    else
      break;
    }
  }
}


int Connect4::MakeMoveInColumnTest(){
  if (PlayerOneTurn){
    PlayerOneTurn = false;

    do{
    std::cout << "enter a interger from 1 to 7: ";
    std::cin >> PlayersMove;
    Height = Connect4::CountHeight(PlayersMove);
    } while (Height >= rows);
    rows_cols = std::make_pair(-Height+5,PlayersMove-1);
    Board[-Height + 5][PlayersMove-1] = Player1;
  }

  else{
    PlayerOneTurn = true;

    do{
    std::cout << "enter a interger from 1 to 7: ";
    std::cin >> PlayersMove;
    Height = Connect4::CountHeight(PlayersMove);
    } while (Height >= rows);
    rows_cols = std::make_pair(-Height+5,PlayersMove-1);
    Board[-Height+5][PlayersMove-1] = Player2;
  }
  Moves++;
  InColumn();
  return (Win);
}

int Connect4::MakeMoveInRowTest(){
  if (PlayerOneTurn){
    PlayerOneTurn = false;

    do{
    std::cout << "enter a interger from 1 to 7: ";
    std::cin >> PlayersMove;
    Height = Connect4::CountHeight(PlayersMove);
    } while (Height >= rows);
    rows_cols = std::make_pair(-Height+5,PlayersMove-1);
    Board[-Height + 5][PlayersMove-1] = Player1;
  }

  else{
    PlayerOneTurn = true;

    do{
    std::cout << "enter a interger from 1 to 7: ";
    std::cin >> PlayersMove;
    Height = Connect4::CountHeight(PlayersMove);
    } while (Height >= rows);
    rows_cols = std::make_pair(-Height+5,PlayersMove-1);
    Board[-Height+5][PlayersMove-1] = Player2;
  }
  Moves++;

  InRow();
  return Win;

}




