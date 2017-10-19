#include <iostream>
#include <string>
#include <vector>
#include <map>
//----------------------------------------------------//
//----------------------------------------------------//
//----------------------------------------------------//
#ifndef TOKENIZE_H
#define TOKENIZE_H
//----------------------------------------------------//
using namespace std;

/* This class is meant to tokenize an input to be passed
   into the lexime part of out interpreter. We will make use of the
   map class to put one item coupled with another */
class tokenize{
public:
    //initialize the variables
    tokenize();
    //map function
    void input_in(string in_line);
    //AUXILLARY FUNCTIONS
    //The purpose of these functions is to provide help
    //for parsing inputed syntax
    int find(string line, char target);
    //Breaking function. Divides the list up into two arrays
    vector<char> break_line(string line, int target);

private:
  vector<string> declare_syntax;
  vector<string> math_op;
};



#endif
