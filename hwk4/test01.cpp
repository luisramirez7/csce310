#include "csce310homeWork04part01.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main( int argc , char* argv[] ){
  int number;
  int sum = 0;
  vector<double> numbers;
  while( cin >> number ){
    numbers.push_back( number * 1.0 );
    sum += number;
  }

  for( int i = 0; i < numbers.size(); i++ ){
    numbers[i] /= sum;
  }
  
  try{
    fprintf( stdout , "At best, %.2f comparisons are needed on average\n" , optimalBST( numbers ) );
  }
  catch( exception e ){
    cerr << "ERROR" << endl;
  }
}
