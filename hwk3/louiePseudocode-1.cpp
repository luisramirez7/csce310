#include <vector>
#include "csce310homeWork03part01.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <set>
#include <queue>

int findFirstMin(vector<double>rows, vector<int>visited){
	int min_element = *std::max_element(rows.begin(), rows.end());

	for (int a = 0; a < rows.size(); a++)
	{
		if(rows[a] < min_element && rows[a] != 0 && visited[a] == false)
		{
			min_element = rows[a];
		}
	}
	return min_element;
}

int findIndexOf(vector<double> row, int elementYouAreLookingFor, vector<int>visited){
	for (int p = 0; p < row.size(); p++)
	{
		cout << row[p] << ", "; 
	}
	vector<double>::iterator z = row.begin();

	while(z != row.end()){
		z++;
	}

	z = find(row.begin(), row.end(), elementYouAreLookingFor);

	int truePosition = distance(row.begin(), z);
	cout << "Min found at position: " << truePosition << endl;
	
	return truePosition;
}

int executeProcessingSession(vector< vector<double> > matrix, vector<bool> visited) {
	
	for(int i = 0; i < matrix.size(); i++) {

									//We only want to iterate over the rows
									// of nodes which are *already* part of the MST
		if(visited[i] == false) { //  the current node is not part of the MST
			continue; // Skip
		}

		for(int j = 0; j < matrix.size(); j++) {

			// We only want to iterate over the columns 
			// of nodes which are *not yet* part of our MST
			if(visited[j] == true) {
				continue; // If connected, skip
			}

			if( matrix[i][j] ) {
			 	   //is smaller than the
			   	   //weight of the previously smallest edge
				   // Forget about the previous value
				   // and keep track of this new value and its 
				   // corresponding node (j) from now on
			}	
		}
	}
	
	// Add the smallest found value in this iteration to the TOTAL
	// Add the node which held the smallest found weight to the MST
	
	return 0;
}

double processMatrix(vector< vector<double> > matrix) {
	
	vector<bool> visited;// Add the first node to the MST
	
	for (int ai = 0; ai < matrix.size(); ai++)
	{
		visited.push_back(false);
	}

	visited[0] = true;

	// Find the smallest weight in first row
	// Add its corresponding node to the MST
	// Add its weight to the TOTAL
	int min = findFirstMin(matrix[0], visited);
	int minIndex = findIndexOf(matrix[0], min, visited);
	
	visited[minIndex] = true;

	// Now, process the entire matrix n-2 times
	for(int i = 0; i < matrix.size()-2; i++) {
		executeProcessingSession(matrix, visited);
	}
	
	return 0; // Return TOTAL
}



vector< vector<double> > initTestMatrix() {
	
	vector<double> v1 = {0, 0, 0, 6, 1};
	vector<double> v2 = {0, 0, 1, 0, 2};
	vector<double> v3 = {0, 1, 0, 0, 4};
	vector<double> v4 = {6, 0, 0, 0, 3};
	vector<double> v5 = {1, 2, 4, 3, 0};

	vector< vector<double> > m;
	m = m.resize(5, vector<int>(5, 0));
	m[0] = v1;
	m[1] = v2;
	m[2] = v3;
	m[3] = v4;
	m[4] = v5;
	
	return m;
}

int main() {

	vector< vector<double> > matrix = initTestMatrix();
	
	double answer = processMatrix(matrix);

	cout << answer << "\n";
}