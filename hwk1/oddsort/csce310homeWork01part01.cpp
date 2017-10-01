#include "csce310homeWork01part01.h"
#include <iostream> 
using namespace std;

unsigned long long int oddDigits( unsigned long long int digits ){

	string individualDigits = to_string(digits);
	int oddDigitsInDigits = 0;
	int i;
	for(i = 0; i < individualDigits.length(); i++){
		if (individualDigits[i] % 2 != 0){
			oddDigitsInDigits++;
		}
	}
	
	return oddDigitsInDigits;
}