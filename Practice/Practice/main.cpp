#include <iostream>
#include <string.h>

using namespace std;

int main() {

int strInt;
int arrSize = 11;
char str = '9'; // ASCII 57
int ascInt = int(str); //Cast ASCII as Int
int numArr[11];
char charArr[11];

strInt = ascInt - '0'; //Subtract ACII 48, char '0', to get int 9


cout << ascInt << endl;
cout << strInt << endl;

for (int i=0; i<=11; i++) {
        numArr[i] = 9;
        cout << numArr[i];
}
cout << endl;

//Enter the user's input string into the array
string userIn = "32768";

//Find the size of userIn
int sizeNum = userIn.length();

//Output the indexed digit
cout << userIn[2] << endl; //index 2 should print 7

//Print the size of userIn
cout << sizeNum << endl;

//Populate array with char 0
for (int i=0; i<=11; i++) {
        charArr[i] = '0';
        cout << charArr[i];
}

//Populate the end of the array with the user input
for (int i=0; i<sizeNum; i++) {
    charArr[i + 11 - sizeNum] = userIn[i];
}

//Uhhhh... Create another number object to do some math on
string userIn2 = "4000";
int sizeNum2 = userIn2.length();
char charArr2[arrSize];
for (int i=0; i<=arrSize; i++) {
        charArr2[i] = '0';
        cout << charArr2[i];
}
for (int i=0; i<sizeNum; i++) {
    charArr2[i + arrSize - sizeNum] = userIn2[i];
}

//Do some math
for (int i=0; i<arrSize; i++) {
cout << (charArr[i + arrSize - sizeNum] + charArr2[i + arrSize - sizeNum2]);
arrSize--;
}

    return 0;
}
