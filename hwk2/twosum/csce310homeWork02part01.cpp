#include <vector>
#include "csce310homeWork02part01.h"
#include <cmath>
#include <iostream>
#include <algorithm> 
#include <map>

using namespace std;

bool sumToN( vector<int> number , int value ){
	int i;
	int j;
	for(i = 0; i < number.size(); i++){
		for(j = i+1; j < number.size(); j++){
			if (number[j] == value - number[i])
			{
				return true;
			}
		}
	}
	
  return false;
}
