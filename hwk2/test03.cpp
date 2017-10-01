#include "csce310homeWork02part03.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main( int argc , char* argv[] ){
  int i;
  cin >> i;
  vector<int> number;
  int num;
  while( cin >> num ){
    number.push_back( num );
  }
  printf( "%d comparisons are needed.\n" , ourQuickSelect( number , i ) );
}
