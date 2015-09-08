#include "bigint.h"
#include <iostream>
#include <string>

using namespace std;

BigInt::BigInt(){

}

BigInt::BigInt(const char* str) {

    int sizeNum = sizeof(str);
    char charArr[NUM_DIGITS + 1];
    for (int i=0; i<=(NUM_DIGITS + 1); i++) {
            charArr[i] = '0';
    }
    for (int i=0; i<sizeNum; i++) {
        charArr[i + (NUM_DIGITS + 1) - sizeNum] = str[i];
    }

    cout << charArr[i];

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
	return "";
}

