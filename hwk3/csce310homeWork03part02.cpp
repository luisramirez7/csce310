#include <vector>
#include "csce310homeWork03part02.h"
#include <cmath>
#include <iostream>

using namespace std;

vector< vector<double> > allPairsSP( vector< vector<double> > adjacencyMatrix , int i ){
  
  int iteration = i;

  for (int j = 0; j < iteration; j++)
  {
  	for (int row = 0; row < adjacencyMatrix.size(); row++)
  	{
  		for (int column = 0; column < adjacencyMatrix.size(); column++)
  		{
  			if (adjacencyMatrix[row][column] != -1 && (adjacencyMatrix[row][column] > (adjacencyMatrix[row][j] + adjacencyMatrix[j][column])) && adjacencyMatrix[row][j] != -1 && adjacencyMatrix[j][column] != -1)
  			{
  				adjacencyMatrix[row][column] = adjacencyMatrix[row][j] + adjacencyMatrix[j][column]; 
  			}else if (adjacencyMatrix[row][column] == -1 && adjacencyMatrix[row][j] != -1 && adjacencyMatrix[j][column] != -1 && adjacencyMatrix[j][row] != -1){
  				adjacencyMatrix[row][column] = adjacencyMatrix[row][j] + adjacencyMatrix[j][column];
  			}
  		}
  	}
  }
  return adjacencyMatrix;
}
