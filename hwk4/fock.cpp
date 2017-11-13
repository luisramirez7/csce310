#include "csce310homeWork04part01.h"
#include <limits> 
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double optimalBST( vector<double> numbers ){
	int nodes = numbers.size(); //11
	vector<vector<double> > probabilityMatrix(nodes+1, vector<double>(nodes+1, 0)); //We want 12 rows, and 12 cols.

	for(int y = 0; y < probabilityMatrix.size(); y++){
		probabilityMatrix[y][y] = 0;
		probabilityMatrix[y][y+1] = numbers[y];
	}

	for (int row = 0; row < numbers.size(); row++)
	{
		for (int columns = 2; columns < numbers.size(); columns++)
		{
			int temporary = row + columns;
		}
	}

	for (int p = 0; p < probabilityMatrix.size(); p++)
	{
		for (int z = 0; z < probabilityMatrix.size(); z++)
		{
			cout << probabilityMatrix[p][z] << "\t";
		}
	}

	

  return probabilityMatrix[0][numbers.size()];
}