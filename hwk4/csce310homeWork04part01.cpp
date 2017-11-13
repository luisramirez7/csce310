#include "csce310homeWork04part01.h"
#include <limits> 
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double optimalBST( vector<double> numbers ){
	double nodes = numbers.size(); //11
	vector<vector<double> > probabilityMatrix(nodes+1, vector<double>(nodes+1, 0)); //We want 12 rows, and 12 cols.

	for(double y = 0; y < numbers.size(); y++){
		probabilityMatrix[y][y] = 0;
		probabilityMatrix[y][y+1] = numbers[y];
	}
	probabilityMatrix[numbers.size()][numbers.size()] = 0;

	for (double d = 2; d <= numbers.size(); d++)
	{
		for (double i = 0; i <= numbers.size()-d; i++)
		{
			double j = i + d;
		
			double min = 999.0;
			
			for(double k = i; k < j; k++)
			{
				if (probabilityMatrix[i][k] + probabilityMatrix[k+1][j] < min)
				{
					min = probabilityMatrix[i][k] + probabilityMatrix[k+1][j];
				}

			}
			
			double sum = numbers[i];

			for (double s = i+1; s < j; s++)
			{
				sum = sum + numbers[s];
			}
			
			probabilityMatrix[i][j] = min + sum;
		}
	}
  return probabilityMatrix[0][numbers.size()];
}



