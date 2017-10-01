#include "csce310homeWork01part02.h"
#include <string>
#include <iostream>
#include <algorithm> 

using namespace std;

void printPermutations( string word , int permutations )
{
  sort(word.begin(), word.end());
  int theCurrentPermutation;
  cout << word << endl;
  for( int theCurrentPermutation = 0;  theCurrentPermutation < permutations-1; theCurrentPermutation++ ){
  	//Step 1 find first character index
    int aSubI;
    int aSubJ;
    int j;
    int k;

    for (int j = 0; j < word.length() - 1; j++)
    {
      if (word[j] < word[j+1])
        {
          aSubI = j;
        }
  	}
    // Step 2 find second character index
    for (int k = 0; k < word.length(); k++)
    {
      if (word[aSubI] < word[k])
        {            
          aSubJ = k;
        }
    }
    //Step 3 swap indeces
    swap(word.at(aSubI), word.at(aSubJ));
    //Step 4 reverse the swapped string
    reverse(word.begin() + aSubI + 1, word.end());
    cout << word << endl;
  } 

  return;
}