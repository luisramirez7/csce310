#include "csce310homeWork04part01.h"
#include <limits> 
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

double optimalBST( vector<double> numbers ){
	int nodes = numbers.size(); //11
	vector<vector<double> > probabilityMatrix(nodes+1, vector<double>(nodes, 0)); //We want 12 rows, and 12 cols.

	for(int i = 1; i < probabilityMatrix.size(); i++){
		probabilityMatrix[i][i-1] = 0;
		probabilityMatrix[i][i] = numbers[i-1];
		cout << "DIAG: " << probabilityMatrix[i][i-1] << endl;
		cout << "PROBABILITY AT: "<< i << "," << i << ": "<< probabilityMatrix[i][i] << endl;
	}

	probabilityMatrix[nodes][nodes-1] = 0; // matrix index at the original size + 1 (12 row, which is the 11th index) and original size (which is 11, which is the 10th index)

	cout << "Row count: " << probabilityMatrix.size() << endl;
	cout << "Col count: " << probabilityMatrix[0].size() << endl;
	cout << "Bottom right hand corner: " << probabilityMatrix[11][11] << endl;
	cout << "Extra row and col created? " << probabilityMatrix[11][10] << endl; //should be 0
	for (int d = 1; d < probabilityMatrix.size()-1; d++)
	{
		cout << "i'm d" << d << endl;
		for(int b = 1; b < probabilityMatrix.size()-d; b++)
	 	{
			cout << "i'm index: "<< b << "," << d << " with value: " << probabilityMatrix[d][b] << endl;
			int j = b+d;
			int min_value = 999;
			// NOT TRAVERSING CORRECTLY, SETS ALL MINS TO 0, NOT NEW MIN
			for(int k = b; b < j; b++)
			{
				if (probabilityMatrix[b][k-1] + probabilityMatrix[k+1][j] < min_value)
				{
					min_value = probabilityMatrix[b][k-1] + probabilityMatrix[k+1][j];
				}

				int sum = numbers[b];
				for (int s = b+1; b < j; s++)
				{
					sum = sum + numbers[s];
				}
				probabilityMatrix[b][j] = min_value + sum;
			}
		}
	}

  return 0;
}

