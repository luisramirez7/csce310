#include "OurCSCE310Tree.h"
#include <iterator>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

int main( int argc , char* argv[] ){
  ifstream addsFile( argv[1] );
   
  istream_iterator<int> aStart(addsFile),aEnd;
  
  vector<int> adds(aStart,aEnd);
  
  OurCSCE310Tree tree;

  for( int a = 0; a < adds.size(); a++ ){
    try{
      tree.insert( adds[a] );
    }
    catch(...){
      cerr << "An error occurred in rotation" << endl;
    }
  }

  try{
    tree.printPreorder();
    cout << endl;
    tree.printInorder();
    cout << endl;
    tree.printPostorder();
    cout << endl;
  }
  catch(...){
    cerr << "An error occurred in printing" << endl;
  }
  return 0;
}
