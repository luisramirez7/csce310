#include <vector>
#include "csce310homeWork03part01.h"
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
/*
Program finds the minimum spanning tree outputting the length of the shortest path.
It will go through each index value to find the smallest node in check .
Once the smallest node is chosen it will be stored in path vector to calculate the shortest path.
The path vector will be called at the end to sum up the shortest length pathSum
*/
double minimumST( vector< vector<double> > adjacencyMatrix ){
  vector<int> check; //used to check if edge has been used already
  vector <int> path; //stores edges
  int matrixRow = adjacencyMatrix.size();
  int pathSum=0;

  int col=-1; //used to store the selected edge
//instaniating check vector
  for (int i=0; i<matrixRow; i++){
    check.push_back(0);
  }
  check[0]=1;


  //while edges are not all called, 0 meaning not called, continue finding it
while(std::find(check.begin(),check.end(),0)!=check.end()){
  int min = -1; //mark it as a value node can never be
    for(int i=0; i<matrixRow; i++){
     for (int j=0; j<matrixRow;j++){
       if(check[i]==1){ //start at nodes that have been touched
         if(check[j]==0){ //only using columns that haven't been  an edge
           if ((min>adjacencyMatrix[i][j]||min==-1) && adjacencyMatrix[i][j]!=0){
             min=adjacencyMatrix[i][j];
             col=j; //stores min's column so it can later be marked done
           }
         }
       }
       }
   }
   path.push_back(min); //add edge to mst
   check[col]=1; //the selected edge is used



}

  //sum up edges of shortest path
  for(int i=0; i<path.size();i++){
    pathSum+=path[i];
  }
  return pathSum;
}
