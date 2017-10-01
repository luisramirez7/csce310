#include <vector>
#include "csce310homeWork02part03.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int louiesQuickSelect( vector<int> number , int position, int comparisons ){
	vector<int>lefthandside;
	vector<int>righthandside;
	
	int pivot = number[0];

	for (int i = 0; i < number.size(); ++i)
	{
		if (number[i] < pivot){
			lefthandside.push_back(number[i]);
		} else if (number[i] > pivot){
			righthandside.push_back(number[i]);
		}
	}

	comparisons = comparisons + lefthandside.size() + righthandside.size();

	if (lefthandside.size() == position - 1)
	{
		return comparisons;
	} else if (lefthandside.size() > position - 1){
		return louiesQuickSelect(lefthandside, position, comparisons);
	} else if (lefthandside.size() < position - 1){
		return louiesQuickSelect(righthandside, (position - lefthandside.size() - 1), comparisons);
	};
}

int ourQuickSelect(vector<int> number, int position){
	return louiesQuickSelect(number, position, 0);
}

