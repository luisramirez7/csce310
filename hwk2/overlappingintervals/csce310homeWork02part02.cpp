#include <vector>
#include "csce310homeWork02part02.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map> 

using namespace std;

int overlappingIntervals( vector<int> start , vector<int> end ){

	vector<int> bigassvector;
	
	for (int i = 0; i < start.size(); ++i)
	{
		bigassvector.push_back(start[i]);
		bigassvector.push_back(end[i]);
	}
	
	sort(bigassvector.begin(), bigassvector.end());
	
	map<int , int> startKeys;

	for(int k = 0; k < start.size(); k++){
		startKeys[start[k]] = end[k];
	}
	
	int intervalcounter = 0;

	vector<int> foundHistogram;
	
	for (int p = 0; p < bigassvector.size(); p++)
	{
		if (startKeys.count(bigassvector[p]) > 0)
		{
			++intervalcounter;
			foundHistogram.push_back(intervalcounter);
		} else {
			--intervalcounter;
			foundHistogram.push_back(intervalcounter);
		}
	}

  return *std::max_element(foundHistogram.begin(), foundHistogram.end());
}

