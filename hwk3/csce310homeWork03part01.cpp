#include <vector>
#include "csce310homeWork03part01.h"
#include <cmath>
#include <iostream>

using namespace std;

vector<bool> alreadyVisitedVector;
int valueOfMstFinal;

int doMath(vector< vector<double> > matrix){
	int minVal;
	int indexOfMin;
	int current;

	for (int i = 0; i < matrix.size(); i++)
	{
		minVal = 0;
		indexOfMin = 0;
		current = 0;
		
		if (alreadyVisitedVector[i] == false)
		{
			continue;
		}

			for (int j = 0; j < matrix.size() ; ++j)
			{
				if (alreadyVisitedVector[j] == true)
				{
					continue;
				}

				current = matrix[i][j];

				if (current != 0 && minVal == 0)
				{
					minVal = current;
					indexOfMin = j;
				}

			}
			valueOfMstFinal += minVal;

			alreadyVisitedVector[indexOfMin] = true;
	}

	return 0;
}

int createUsed(vector< vector<double>> adjacencyMatrix){
	
	for (int z = 0; z < adjacencyMatrix.size(); z++)
	{
		alreadyVisitedVector.push_back(false);
	}

	alreadyVisitedVector[0] = true;

	return 0;
}

double minimumST( vector< vector<double> > adjacencyMatrix ){
  
  createUsed(adjacencyMatrix);
  doMath(adjacencyMatrix);

  return valueOfMstFinal;
}
