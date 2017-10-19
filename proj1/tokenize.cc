#include "tokenize.h"

using namespace std;
//initialize array that holds syntax
tokenize::tokenize(){
  declare_syntax.push_back("Str"); //for right now we will have string, integers, characters, and doubles
  declare_syntax.push_back("Int");
  declare_syntax.push_back("Chr");
  declare_syntax.push_back("Dbl");
  math_op.push_back("+");
  math_op.push_back("-");
  math_op.push_back("*");
  math_op.push_back("/");
  }
int tokenize::find(string line, char target){
  string::iterator itr;
    for (itr = line.begin(); itr!=line.end(); itr++){
      if (*itr == target){
        return *itr;
      }
    }
    return -1;

  }
vector<char> tokenize::break_line(string line, int target){
	//Note, It is assumed that find will always be used before this statement.
	int position = target;
		string::iterator itr;
		vector<char>broken_line;
		//Push the position+1 into a new vector to be returned
			for(itr = line.end();*itr != position+1;	itr--){
				broken_line.push_back(*itr);
			}
			line.resize(position);
			return broken_line;
  }
