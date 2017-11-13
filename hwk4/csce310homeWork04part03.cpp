#include "csce310homeWork04part03.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool makeThreeGroups( vector<int> numbers ){
    //Check if there can actually be 3 groups in the first place
	int sum_all = 0;
	vector<bool> possible;
	for (int i = 0; i < numbers.size(); i++)
	{
		sum_all += numbers[i];
	}
    //If it isn't possible return false, if it is possible, do the algorithm
	if (sum_all % 3 != 0)
	{
		return false;
	} else {
		for (int j = 1; j < numbers.size()-1; j++)
		{
			if (numbers[j-1] + number[j])
			{
				/* code */
			}
		}
	}

  return numbers.size() % 2 == 0;
}
