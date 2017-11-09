#include <vector>
#include "csce310homeWork03part01.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <set>
#include <queue>

using namespace std;

double minimumST( vector< vector<double> > adjacencyMatrix ){

	vector<bool> visitedVertices;

	for (int i = 0; i < adjacencyMatrix.size(); i++)
	{
		visitedVertices.push_back(false);
	}

	int valueOfMstFinal = 0;
	
	visitedVertices[0] = true;
	while( std::find(visitedVertices.begin(), visitedVertices.end(),false) != visitedVertices.end()){ //While you haven't visted
		
		int initMin = -1
		
		for (int row = 0; row < adjacencyMatrix.size(); row++)
		{
			for (int column = 0; column < adjacencyMatrix.size(); column++)
			{
				if (visitedVertices[row] == true)
				{
					if (visitedVertices[column] == false)
					{
						if (initMin > adjacencyMatrix[row][column] && adjacencyMatrix[row][column] != 0)
						{
							initMin = adjacencyMatrix[row][column]; //Reset the value of initMin to a new min if found
							columnSelected = j;
							visitedVertices[column] = true;
						}
					}
					
				}
			}
		}
		valueOfMstFinal += initMin;
		visitedVertices[columnSelected];
	}

  return valueOfMstFinal;
}