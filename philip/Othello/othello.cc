//Othello game Implimentation
//Philip Iler | project 7 | 11-24-15

#include "othello.h"
#include "board.h"
#include <iostream>
#include <string>
#include "colors.h"
#include "piece.h"
#include "game.h"
#include <queue>

void othello::display_status()const
{

  std::cout << B_GREEN << " "; //Top Coords Offset

  for(int too_many_vars = 0; too_many_vars < 8; ++too_many_vars)
    std::cout << "\e(0\x78\e(B " << char('A' + too_many_vars) << ' '; //Print A,B,C...

  std::cout << "\e(0\x78" <<  RESET << std::endl <<  B_GREEN << "\x71\e(B"; //Print Right Bar For Top Coords

  for(int too_many_vars = 0; too_many_vars < 8; ++too_many_vars) //Bottom Grid Stuff
    std::cout << B_GREEN << "\e(0\x6e\x71\x71\x71\e(B" << RESET;

  std::cout << B_GREEN << "\e(0\x75\e(B" << RESET << std::endl;

  for(int j = 0; j < 8; ++j)
  {
    std::cout << B_GREEN << j+1 << RESET; // Print Numbers On Side
    for(int i = 0; i < 8; ++i)
      {
        if (game_board.get_game_data(i, j).get_data() == piece::EMPTY)
        {
          std::cout << B_GREEN << "\e(0\x78\e(B   " << RESET;
        }else if(game_board.get_game_data(i, j).get_data() == piece::WHITE){
          std::cout << B_GREEN << "\e(0\x78" << WHITE << " \x60\e(B " << RESET;
        }else{
          std::cout << B_GREEN << "\e(0\x78" << BLACK << " \x60\e(B " << RESET;
        }
      }

    std::cout << B_GREEN << "\e(0\x78" << RESET << std::endl << B_GREEN << "\x71\e(B";

    if(j != 7)
      {
      for(int too_many_vars = 0; too_many_vars < 8; ++too_many_vars) //More Bottom Grid Stuff
	std::cout << "\e(0\x6e\x71\x71\x71\e(B";
      std::cout << "\e(0\x75\e(B" << RESET << endl;
      }
    else
      {
      for(int foo = 0; foo < 8; ++foo)
        std::cout << "\e(0\x76\x71\x71\x71\e(B";
      std::cout << "\e(0\x6a\e(B" << RESET << std::endl;
      }
  }

}

void othello::restart()
{
  std::cout << "RESTARTING\n";
  game_board.setup();
  pass_count == 0;
}

void othello::make_move(const std::string& s)
{
  if(s != "\n")
    {
      int i, j;
      get_coords(s, i, j);
      game_board.mod_game_data(i, j, othello_who());
      for(int x = -1; x <= 1; ++x)
	for(int y = -1; y <= 1; ++y)
	  do_move(i, j, x, y);
      pass_count = 0;
    }

  ++pass_count;

  main_savitch_14::game::make_move(s);
}

bool othello::is_legal(const std::string& s)const
{
  if(s == "\n")
    return 1;

  int i, j;
  get_coords(s, i, j);

  if(game_board.get_game_data(i, j).get_data() == piece::EMPTY)
     for(int x = -1; x <= 1; ++x)
	for(int y = -1; y <= 1; ++y)
	  if(do_legal(i, j, x, y, 0))
	    return 1;
  return 0;
}

std::string othello::get_user_move()const
{
  std::queue<std::string> tmp;
  compute_moves(tmp);

  if(tmp.front() == "\n")
    return "\n";

  std::string s;
  std::cout << "Black's Turn\n";
  std::cout << "Enter Coordinates in format \"A1\">";

  while(std::cin.peek() == '\n')
    std::cin.ignore();

  std::getline(cin, s);
  return s;
}

void othello::get_coords(const std::string s, int& i, int& j)const
{
  i = toupper(s[0]) - 'A';
  j = s[1] - '1';
}

bool othello::do_move(const int i, const int j, const int x, const int y)
{
  piece::piece_dat tmp;
  tmp = game_board.get_game_data(i + x, j + y).get_data();
  if(x == 0 && y == 0)
    return 0;
  if(i == -1 || j == -1 || i == 8 || j == 8 || tmp == piece::EMPTY)
    return 0;
  if(tmp == othello_who())
    return 1;
  if(do_move(i + x, j + y, x, y))
    {
    game_board.flip(i + x, j + y);
    return 1;
    }

  return 0;
}

bool othello::do_legal(const int i, const int j, const int x, const int y, const int n)const
{
  piece::piece_dat tmp, ptmp;
  tmp = game_board.get_game_data(i + x, j + y).get_data();
  ptmp = game_board.get_game_data(i, j).get_data();
  if(x == 0 && y == 0)
    return 0;
  if(i == -1 || j == -1 || i == 8 || j == 8 || tmp == piece::EMPTY)
    return 0;
  if(tmp == othello_who())
    if(ptmp == othello_not_who())
      return 1;
    else
      return 0;
  return(do_legal(i + x, j + y, x, y, n + 1));
}

piece::piece_dat othello::othello_who() const
{
  if(game::moves_completed()%2 == 0)
    return piece::BLACK;
  else
    return piece::WHITE;
}

piece::piece_dat othello::othello_not_who() const
{
  if(game::moves_completed()%2 == 0)
    return piece::WHITE;
  else
    return piece::BLACK;
}

bool othello::is_game_over()const
{
  for(int j = 0; j <= 8; ++j)
    for(int i = 0; i <= 8; ++i)
      for(int x = -1; x <= 1; ++x)
	for(int y = -1; y <= 1; ++y)
	  if(game_board.get_game_data(i, j).get_data() == piece::EMPTY && do_legal(i, j, x, y, 0))
	      return 0;

  if(pass_count > 1)
    return 0;
  return 1;
}

void othello::game_end()const
{
  int b = 0, w = 0;

  for(int j = 0; j <= 8; ++j)
    for(int i = 0; i <= 8; ++i)
      if(game_board.get_game_data(i, j).get_data() == piece::BLACK)
	++b;
      else if(game_board.get_game_data(i, j).get_data() == piece::WHITE)
	++w;

  if(b > w)
    std::cout << "Black Wins!\n";
  else if (b < w)
    std::cout << "White Wins!\n";
  else
    std::cout << "TIE!\n";
}

main_savitch_14::game* othello::clone()const
{
  othello* tmp;
  tmp = new othello();
  tmp->pass_count = pass_count;
  tmp->game_board = game_board;

  return tmp;
}

void othello::compute_moves(std::queue<std::string>& moves)const
{
  std::string tmp;
  for(int j = 0; j < 8; ++j)
    for(int i = 0; i < 8; ++i)
      for(int x = -1; x <= 1; ++x)
	for(int y = -1; y <= 1; ++y)
	  if(game_board.get_game_data(i, j).get_data() == piece::EMPTY && do_legal(i, j, x, y, 0))
	  {
	    tmp += char('A' + i);
	    tmp += char('1' + j);
	    moves.push(tmp);
	    tmp = "";
	    x = 2;
	    y = 2;
	  }

  if(moves.empty())
    {
      std::cout << "PASS\n";
    moves.push("\n");
    }
  return;
}

int othello::evaluate()const
{
  int tmp;
  for(int j = 0; j < 8; ++j)
    for(int i = 0; i < 8; ++i)
      if(game_board.get_game_data(i, j).get_data() == piece::WHITE)
	{

	}
  else if(game_board.get_game_data(i, j).get_data() == piece::BLACK)
  	{
        --tmp;
    }
  return tmp;
}

main_savitch_14::game::who othello::winning()const
{
int b = 0, w = 0;

  for(int j = 0; j <= 8; ++j)
    for(int i = 0; i <= 8; ++i)
      if(game_board.get_game_data(i, j).get_data() == piece::BLACK)
	++b;
      else if(game_board.get_game_data(i, j).get_data() == piece::WHITE)
	++w;

  if(b > w)
    return main_savitch_14::game::HUMAN;
  else if (b < w)
    return main_savitch_14::game::COMPUTER;
  else
    return main_savitch_14::game::NEUTRAL;
}
