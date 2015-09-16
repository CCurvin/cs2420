//Author: Chad Curvin
//Class: cs2420
//Description: Create a BigInt class that stores and performs arithmetic on extraordinarily large numbers

#ifndef BIG_INT_H
#define BIG_INT_H

#include <string>

using std::string;

class BigInt
{
public:
	//constructors
	BigInt();
	BigInt(const char*);
	//BigInt(const BigInt&);

	//operators
	BigInt add(const BigInt&) const;
	BigInt operator+(const BigInt&) const;
	BigInt subtract(const BigInt&) const;
	BigInt operator-(const BigInt&) const;
	string convertToString() const;

private:
	//Add any private members you want

	static const int NUM_DIGITS = 100;
	int numArr[NUM_DIGITS + 1];
	void tensComplement();
	int* getTensComplement() const;
	bool isNeg;

};

#endif
