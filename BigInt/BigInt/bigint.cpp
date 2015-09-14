#include "bigint.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

using namespace std;

BigInt::BigInt(){
    //Populate array with zeros
    for (int i=0; i<=(NUM_DIGITS +1); i++) {
        numArr[i] = 0;
    };
}

BigInt::BigInt(const char* str) {

    //Populate array with zeros
    for (int i=0; i<=(NUM_DIGITS + 1); i++) {
        numArr[i] = 0;
    };


	//Check if str[0] is a negative sign
    if (str[0] != '-') {
        isNeg = false;
    } else {
        isNeg = true;
    };

    //Get int length
    int sizeInput = strlen(str);

	//Populate numArr with input
	for (int i=0; i<=sizeInput; i++) {
        //curr is the current position of i, plus the size of the array (to get to the
        //last index) minus the size of the input string to get to the first position
        //in the array where the string of numbers needs to go
		int curr = i + (NUM_DIGITS + 1) - sizeInput;
        numArr[curr] = str[i] - '0';
	};

}

BigInt BigInt::add(const BigInt& rightOperand) const {

    //Create an object to return
	BigInt addArr;

	//Loop through array and and perform addition on each index
	for (int i=0; i<=NUM_DIGITS; i++) {
	addArr.numArr[i] = this->numArr[i] + rightOperand.numArr[i];
	};

	return addArr;
}

BigInt BigInt::operator+(const BigInt& rightOperand) const {

	return this->add(rightOperand);
}

BigInt BigInt::subtract(const BigInt& rightOperand) const {
	BigInt objToReturn("0");
	return objToReturn;
}

BigInt BigInt::operator-(const BigInt& rightOperand) const {

	return this->subtract(rightOperand);
}

string BigInt::convertToString() const {
	int arrPos;
	int numSize = 0;
	string str;

	//Loop through array to find first non-zero digit
	for (int i=0; i<=(NUM_DIGITS +1); i++) {
		arrPos = i;
		if (numArr[i] != 0) {
			//Set the size of the number
			numSize = (NUM_DIGITS +1) - arrPos;
			break;
		};
	};

    if (isNeg == true) {
        //str[arrPos -1] = '-';
    };

	//Loop through the remaining size of the number, convert it to an int, and concatenate it
		for (int i=arrPos; i<=(NUM_DIGITS +1); i++) {
		str += (numArr[i] + '0');
	};

	return str;
}

