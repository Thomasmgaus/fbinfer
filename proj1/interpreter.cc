#include<iostream>
#include<fstream>
#include "tokenize.h"
// You need to comment more moron
using namespace std;
//Main accepts command line arguments for excecution of interpreter.cc dummy_file.g
int main(int argc, char * argv[]){
//Open ifstream from argv[1]
if (argc != 2){
  cout << "Error, please input a file" <<endl;
  return 0;
}
ifstream file_to_run (argv[1]);
  if (!file_to_run.is_open()){
      cout << "Error Opening filed" << endl  << cout << "Did you Spell the file name correctly?" << endl;
      }
  else{
    string line;
      while(file_to_run){
        getline(file_to_run, line);
        tokenize n;
        //testing the find and break function
					int pos = n.find(line,'=');
					if (pos == -1){
            cout << "not found" <<endl;
					}
          else{
							vector<char>new_line = n.break_line(line, pos);
								for(vector<char>::iterator it = new_line.begin(); it != new_line.end();++it){
									cout << *it;
								}
								for(string::iterator it = line.begin(); it != line.end(); ++it){
									cout << *it;
								}
							}
					}
			}
    file_to_run.close();
}
