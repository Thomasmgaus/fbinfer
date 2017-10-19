//Implimentation for the board class
//Philip Iler | project 7 | 11-24-15

#include "board.h"
#include "piece.h"
#include <iostream>

void board::setup()
{
  for(int i = 0; i < 8; ++i)
    for(int j = 0; j< 8; ++j)
      game_data[i][j].mod_data(piece::EMPTY);

  game_data[3][3].mod_data(piece::WHITE);
  game_data[4][4].mod_data(piece::WHITE);
  game_data[3][4].mod_data(piece::BLACK);
  game_data[4][3].mod_data(piece::BLACK);
  
}

piece board::get_game_data(const int i, const int j)const
{
  return game_data[i][j];
}

void board::mod_game_data(const int i, const int j, piece::piece_dat k)
{
  game_data[i][j].mod_data(k);
}

void board::flip(const int i, const int j)
{
  if(game_data[i][j].get_data() == piece::EMPTY)
    return;

  if(game_data[i][j].get_data() == piece::BLACK)
    {
      game_data[i][j].mod_data(piece::WHITE);
      return;
    }

  if(game_data[i][j].get_data() == piece::WHITE)
    game_data[i][j].mod_data(piece::BLACK);
}
