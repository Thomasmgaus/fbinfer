//Header file for the game board
//Manages the board and the peices on it
//Philip Iler | project 7 | 11-24-15
#ifndef BOARD
#define BOARD

#include "piece.h"

class board
{
public:
  board(){};
  void setup(); //Sets up the board for play
  piece get_game_data(const int i, const int j)const; //Gets that position on the board
  void mod_game_data(const int i, const int j, piece::piece_dat k); //Change the data in that position
  void flip(const int i, const int j); //Flips the peice in that position
private:
  piece game_data[8][8];
};

#endif
