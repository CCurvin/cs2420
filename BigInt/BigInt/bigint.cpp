#include "bigint.h"
#include <iostream>
#include <string.h>

using namespace std;

BigInt::BigInt(){

}

BigInt::BigInt(const char* str) {

    //Get the string length
    int sizeStr = strlen(str);

    //Loop through the array to populate with zeros
    for (int i=0; i<=NUM_DIGITS; i++) {
            numArr[i] = 0;
    }

    //Loop through the array to populate with the new string of digits
    for (int i=0; i<sizeStr; i++) {
        numArr[i + (NUM_DIGITS + 1) - sizeStr] = str[i] - '0';
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
    string str;
    for (int i=0; i<NUM_DIGITS; i++) {
        str[i] = numArr[i] - '0';
    }
    return str;
}

