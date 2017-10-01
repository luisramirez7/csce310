#include "csce310homeWork02part02.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main( int argc , char* argv[] ){
  vector<int> all;
  int num;
  while( cin >> num ){
    all.push_back( num );
  }

  vector<int> start;
  vector<int> end;
  
  for( int i = 0; i < all.size() / 2; i++ ){
    start.push_back( all[i] );
  }

  for( int j = all.size() / 2; j < all.size(); j++ ){
    end.push_back( all[j] );
  }

  try{
    printf( "%d intervals overlap.\n" , overlappingIntervals( start , end ) );
  }
  catch( exception e ){
    cerr << "ERROR" << endl;
  }
  return 0;
}
