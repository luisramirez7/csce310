#include <vector>
#include "csce310homeWork03part01.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <set>
#include <queue>

using namespace std;

int alreadyVisited( vector<int> indexOfVisitedVertices, int current){
	bool already;

	for (int b = 0; b < indexOfVisitedVertices.size(); b++)
	{
		if (indexOfVisitedVertices[current] == indexOfVisitedVertices[b])
		{
			already = true;
			// cout << "Index: " << indexOfVisitedVertices[current] << "has not been visited";
		} else {
			already = false;
			// cout << "Index: " << indexOfVisitedVertices[current] << "has been visited";
		}
	}
	return already;
}

int findMinimumElement( vector<int>allEdges ){
	int min_element = *std::max_element(allEdges.begin(), allEdges.end());

	for (int a = 0; a < allEdges.size(); a++)
	{
		if(allEdges[a] < min_element && allEdges[a] != 0)
		{
			min_element = allEdges[a];
			
		}
	}
	return min_element;
}

int findMinimumElementAgain( vector<int>allEdges, int imHere ){
	allEdges[imHere] = 0;

	int min_element_again = *std::max_element(allEdges.begin(), allEdges.end());
	// if (min_element_again == 0)
	// {
	// 	return min_element_again;
	// }
	for (int a = 0; a < allEdges.size(); a++)
	{
		if(allEdges[a] < min_element_again && allEdges[a] != 0)
		{
			min_element_again = allEdges[a];
		} 
	}
	return min_element_again;
}


int findIndexOf( vector<int> edgesOfVistedVertices, int elementWhoseIndexYoureTryingToFind ){
	for (int p = 0; p < edgesOfVistedVertices.size(); p++)
	{
		cout << edgesOfVistedVertices[p] << ", "; 
	}
	vector<int>::iterator z = edgesOfVistedVertices.begin();

	while(z != edgesOfVistedVertices.end()){
		z++;
	}

	z = find(edgesOfVistedVertices.begin(), edgesOfVistedVertices.end(), elementWhoseIndexYoureTryingToFind);

	int truePosition = distance(edgesOfVistedVertices.begin(), z);
	cout << "Min found at position: " << truePosition << endl;
	
	return truePosition;
} 

double minimumST( vector< vector<double> > adjacencyMatrix ){

	vector<bool> visitedVertices;
	vector<int> indexOfVisitedVertices;
	vector<int>allEdgesOfVisitedVertices;

	for (int i = 0; i < adjacencyMatrix.size(); i++)
	{
		visitedVertices.push_back(false);
	}

	int count = 0;
	int valueOfMstFinal = 0;
	int current = 0; 

	while( count < visitedVertices.size() ){
		if (visitedVertices[current] == false)
		{
			// visitedVertices[current] = true;
			for (int edge = 0; edge < adjacencyMatrix.size(); edge++)
			{
				allEdgesOfVisitedVertices.push_back(adjacencyMatrix[count][edge]);		
			}

			int min_element = findMinimumElement( allEdgesOfVisitedVertices );

			cout << "Min element selected on loop: " << count << " Min element: " << min_element << "               ";

			int visitedVertex = findIndexOf( allEdgesOfVisitedVertices , min_element);

			indexOfVisitedVertices.push_back(visitedVertex);

			bool checker = alreadyVisited( indexOfVisitedVertices, current );

			if (checker == false)
			{
				int newMin = findMinimumElementAgain( allEdgesOfVisitedVertices, visitedVertex );

				valueOfMstFinal += newMin;
			} else if(checker == true){
				valueOfMstFinal += min_element;
			}

			// if (visitedVertices[visitedVertex] == false)
			// {
			// 	valueOfMstFinal += min_element;
			// }  //else if (visitedVertices[visitedVertex] == true)
			// {
			// 	allEdgesOfVisitedVertices[visitedVertex] = 999;
			// 	min_element = findMinimumElement(allEdgesOfVisitedVertices);
			// 	valueOfMstFinal += min_element;
			// }
			
			allEdgesOfVisitedVertices.clear();
			current++;
			count++;
		}// else if (visitedVertices[current] == true)
		// {
		// 	cout << "else";	
		// } 
	}
  return valueOfMstFinal;
}