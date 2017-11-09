#include "csce310homeWork04part02.h"
#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long int pellNumber( unsigned long long int number ){	
	vector<unsigned long long int> previousPells;
	previousPells.push_back(0);
	previousPells.push_back(1);
	
	for (int i = 2; i <= number; i++)
	{
		previousPells.push_back( (2 * previousPells[i-1]) + previousPells[i-2]);
	}
	
	return previousPells.back();
}

