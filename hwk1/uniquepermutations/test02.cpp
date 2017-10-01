#include "csce310homeWork01part02.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main( int argc , char* argv[] ){
  int num;
  cin >> num;
  string word;
  cin >> word;

  try{
    cout << "permutations" << endl;
    printPermutations( word , num );
  }
  catch( exception e ){
    cerr << "An error occurred." << endl;
  }
}
      