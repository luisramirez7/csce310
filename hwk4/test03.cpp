#include "csce310homeWork04part03.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main( int argc , char* argv[] ){
  int number;
  
  vector<int> numbers;
  while( cin >> number ){
    numbers.push_back( number );
  }

  try{
    if( makeThreeGroups( numbers ) ){
      cout << "Three equal groups can be made" << endl;
    }
    else{
      cout << "Three equal groups cannot be made" << endl;
    }
  }
  catch( exception e ){
    cerr << "ERROR" << endl;
  }
}
