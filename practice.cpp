#include <iostream>
#include <string>

using namespace std;

int main() {

int strInt;
char str = '9'; // ASCII 57
int ascInt = int(str); //Cast ASCII as Int
int numArr[101];
char charArr[101];

strInt = ascInt - '0'; //Subtract ACII 48, char '0', to get int 9


cout << ascInt << endl;
cout << strInt << endl;

for (int i=0; i<=101; i++) {
        numArr[i] = 9;
        cout << numArr[i];
}
cout << endl;

//Enter a string
string userIn = "32768";

//Find the size of the user input
int sizeNum = sizeof(userIn);

//Output the indexed digit
cout << userIn.at(2); //index 2 should print 7

//Populate the end of the array with the user input
for (int i=0; i<sizeNum; i++) {
    charArr[i + 101 - sizeNum] = userIn.at(i);
}

for (int i=0; i<=101; i++) {
        charArr[i] = '9';
        cout << charArr[i];
}

    return 0;
}
