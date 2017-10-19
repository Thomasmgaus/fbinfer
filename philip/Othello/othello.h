//Othello game type header file
//Main Implimentation of the game
//Philip Iler | project 7 | 11-24-15

#ifndef OTHELLO
#define OTHELLO

#include "game.h"
#include "board.h"
#include <string>
#include <queue>

class othello : public main_savitch_14::game  
{
public:
  othello(){};
  void display_status()const;
  void make_move(const std::string& s);
  bool is_legal(const std::string& s)const;
  void restart();
  std::string get_user_move()const;
 
  bool is_game_over()const;
  main_savitch_14::game* clone()const;
  void compute_moves(std::queue<std::string>& moves)const;
  int evaluate()const;

  main_savitch_14::game::who winning()const;

  void game_end()const;
  
private:
  void get_coords(const std::string s, int& i, int& j)const; //Converts sting to corrdinates

  bool do_move(const int i, const int j, const int x, const int y);
  //Does move calculations -- uses recursion
  //The direction of the action is determined by the polarity of the x and y vars, they should always
  //Be one or zero. Unsless funky gamplay is desired

  bool  do_legal(const int i, const int j, const int x, const int y, const int n)const;
  //Recursive legal function -- functinos the same as do_move
  //Last parameter should always be zero

  piece::piece_dat othello_who() const;
  piece::piece_dat othello_not_who() const;

  int pass_count;
  board game_board;
};

#endif
