#include "bigint.h"
#include <iostream>
#include <string.h>

using namespace std;

BigInt::BigInt(){
    for (int i=0 i<(NUM_DIGITS +1); i++) {
        numArr[i] = 0;
    }
}

BigInt::BigInt(const char* str) {
	
	//***TODO: Check if str[0] is a negative sign
	//Can use atoi to convert ascii to int

    //Get the string length
    int sizeStr = strlen(str);

    //Loop through the array to populate with zeros
    for (int i=0; i<=NUM_DIGITS; i++) {
            numArr[i] = 0;
    }

    //Loop through the array to populate with the new string of digits
    for (int i=0; i<sizeStr; i++) {
        //curr is the current position of i, plus the size of the array (to get to the
        //last index) minus the size of the input string to get to the first position
        //in the array where the string of numbers needs to go
		int curr = i + (NUM_DIGITS +1) - sizeStr;
		numArr[curr] = str[i] - '0';
    }

}

BigInt BigInt::add(const BigInt& rightOperand) const {
	BigInt objToReturn("0");
	return objToReturn;
}

BigInt BigInt::operator+(const BigInt& rightOperand) const {
	BigInt objToReturn("0");
	return objToReturn;
}

BigInt BigInt::subtract(const BigInt& rightOperand) const {
	BigInt objToReturn("0");
	return objToReturn;
}

BigInt BigInt::operator-(const BigInt& rightOperand) const {
	BigInt objToReturn("0");
	return objToReturn;
}

string BigInt::convertToString() const {
	int arrPos;
	int numSize = 0;
	string charArr;

	//Loop through array to find first non-zero digit
	for (int i=0; i<=(NUM_DIGITS +1); i++) {
		arrPos = i;
		if (numArr[i] != 0) {
			//Set the size of the number
			numSize = (NUM_DIGITS +1) - arrPos;
			break;
		}
	}

	//Loop through the remaining size of the number and concatenate it
	for (int i=arrPos; i<(NUM_DIGITS +1); i++) {
		charArr+= to_string(numArr[i]);
	}

	return charArr;
}

