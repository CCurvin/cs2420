#include "bigint.h"

#include <iostream>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::invalid_argument;
using std::overflow_error;

//This helps with testing, do not modify.
bool checkTest(string testName, string whatItShouldBe, string whatItIs) {

	if (whatItShouldBe == whatItIs) {
		cout << "Passed " << testName << " last digit was: " << whatItIs.at(whatItIs.length()-1) << endl;
		return true;
	}
	else { 
		if (whatItShouldBe == "") {
			cout << "**Failed test " << testName << " ** " << endl << "   Output was "<< whatItIs << endl << "   Output should have been blank. " << endl;
		} else {
			cout << "**Failed test " << testName << " ** " << endl << "   Output was "<< whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
		}
		return false;
	}
}


int main()
{
	BigInt result;

	BigInt num1("999");
	BigInt num2("4873");
	BigInt num3("-739");
	BigInt num4("-9871");
	BigInt num5("123456789012345678901234567890");
	BigInt num6("5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555556");
	BigInt num7("6666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666667");
	BigInt num8("1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111112");
	BigInt num9("-1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	BigInt num10("-30");
	BigInt num11("4444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444443");
	BigInt num12("-8999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
	BigInt num13("-4444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444443");
	BigInt num14("-1");
	BigInt num15("1");

	// Each test is worth one point
	//Tests to see if you even loaded in an BigInt object correctly 
	// Test 1
	checkTest("Test 1", "999", num1.convertToString());
	// Test 2
	checkTest("Test 2", "-739", num3.convertToString());
	
	//Test some addition problems
	// Test 3, negative + negative
	result = num3.add(num4);
	checkTest("Test 3", "-10610", result.convertToString());
	// Test 4, negative + positive
	result = num4.add(num1);
	checkTest("Test 4", "-8872", result.convertToString());
	// Test 5, positive + positive
	result = num8 + num8;
	checkTest("Test 5", "2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222224", result.convertToString());
	// Test 6 positive + negative
	result = num8 + num9;
	checkTest("Test 6", "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111112", result.convertToString());
	// Test 7, negative + positive
	result = num10 + num7;
	checkTest("Test 7", "6666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666637", result.convertToString());
	// Test 8, negative + negative
	result = num10 + num9;
	checkTest("Test 8", "-1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000030", result.convertToString());
	// Test 9, negative + positive
	result = num13 + num6;
	checkTest("Test 9", "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111113", result.convertToString());
	// Test 10, negative + negative
	result = num13 + num9;
	checkTest("Test 10", "-5444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444443", result.convertToString());

	//Some subtraction problems
	// Test 11, positive - positive, negative answer
	result = num1.subtract(num2);
	checkTest("Test 11", "-3874", result.convertToString());
	// Test 12, positive - positive, positive answer
	result = num2.subtract(num1);
	checkTest("Test 12", "3874", result.convertToString());
	// Test 13, negative - negative, negative answer
	result = num4.subtract(num3);
	checkTest("Test 13", "-9132", result.convertToString());
	// Test 14, negative - negative, positive answer
	result = num3.subtract(num4);
	checkTest("Test 14", "9132", result.convertToString());
	// Test 15, positive - positive, negative answer
	result = num5.subtract(num6);
	checkTest("Test 15", "-5555555555555555555555555555555555555555555555555555555555555555555555432098766543209876654320987666", result.convertToString());
	// Test 16 positive - positive, positive answer
	result = num6 - num5;
	checkTest("Test 16", "5555555555555555555555555555555555555555555555555555555555555555555555432098766543209876654320987666", result.convertToString());
	// Test 17, negative - negative, negative answer
	result = num9 - num10;
	checkTest("Test 17", "-999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999970", result.convertToString());
	// Test 18 positive - negative, positive answer
	result = num6 - num9;
	checkTest("Test 18", "6555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555556", result.convertToString());
	// Test 19, negative - negative, positive answer
	result = num9 - num12;
	checkTest("Test 19", "7999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", result.convertToString());
	// Test 20, positive - negative, positive answer
	result = num6 - num13;
	checkTest("Test 20", "9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", result.convertToString());
	// Test 21, negative - positive, negative answer
	result = num13 - num6;
	checkTest("Test 21", "-9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999", result.convertToString());
	// Test 22, zero result
	result = num14 + num15;
	checkTest("Test 22", "0", result.convertToString());
	// Test 23, negative - negative, negative answer
	result = num14 - num15;
	checkTest("Test 23", "-2", result.convertToString());
	// Test 24, positive - negative, positive answer
	result = num15 - num14;
	checkTest("Test 24", "2", result.convertToString());
	// Test 25, negative + negative, negative answer
	result = num14 + num14;
	checkTest("Test 25", "-2", result.convertToString());
	

	// Test 26, Default constructor
	BigInt anInt;
	checkTest("Test 26", "0", anInt.convertToString());

   
        //Bonus Points
        cout << "***Bonus Points***" << endl;
        try{
           BigInt invalid("123Q");
           checkTest("Bonus Test 1", "Invalid Argument Error", invalid.convertToString());
        }
        catch(const invalid_argument& ia){
           checkTest("Bonus Test 1", "0", "0");
        }
        catch(...){
           checkTest("Bonus Test 1", "Invalid Argument Error", "Unexpected Error");
        }

        try{
           BigInt invalid("-");
           checkTest("Bonus Test 2", "Invalid Argument Error", invalid.convertToString());
        }
        catch(const invalid_argument& ia){
           checkTest("Bonus Test 2", "0", "0");
        }
        catch(...){
           checkTest("Bonus Test 2", "Invalid Argument Error", "Unexpected Error");
        }

        try{
           result = num7 + num7;
           checkTest("Bonus Test 3", "Overflow Error", result.convertToString());
        }
        catch(const overflow_error& oe){
           checkTest("Bonus Test 3", "0", "0");
        }
        catch(...){
           checkTest("Bonus Test 3", "Overflow Error", "Unexpected Error");
        }

        try{
           result = num12 - num7;
           checkTest("Bonus Test 4", "Overflow Error", result.convertToString());
        }
        catch(const overflow_error& oe){
           checkTest("Bonus Test 4", "0", "0");
        }
        catch(...){
           checkTest("Bonus Test 4", "Overflow Error", "Unexpected Error");
        }
	return 0;
}
