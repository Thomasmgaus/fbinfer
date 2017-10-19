//Header file for piece class
//Contains information for that patricluar part of the board
//Philip Iler | project 7 | 11-24-15

#ifndef PIECE
#define PIECE



class piece
{
public:
  enum piece_dat {EMPTY, BLACK, WHITE};

  piece_dat get_data(){return data;};
  void mod_data(piece_dat k){data = k;};

private:
  piece_dat data;
};

#endif
