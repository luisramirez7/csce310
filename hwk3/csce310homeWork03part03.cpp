#include <vector>
#include "csce310homeWork03part03.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int hornersRule( vector<int> coeffs , int value ){
	int position = coeffs[0];

	for (int i = 0; i < coeffs.size()-1; i++)
	{
		position = (position*value) + coeffs[i+1];
	}

  return position;
}
