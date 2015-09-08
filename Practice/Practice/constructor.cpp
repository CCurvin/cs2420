#include "bigint.h"
#include <iostream>
#include <string.h>

using namespace std;

BigInt::BigInt() {

}

BigInt::BigInt(const char* str) {
    int sizeNum = sizeof(str);
    char charArr[NUM_DIGITS + 1];
    for (int i=0; i<=(NUM_DIGITS + 1); i++) {
            charArr[i] = '0';
            cout << charArr[i];
    }
    for (int i=0; i<sizeNum; i++) {
        charArr[i + (NUM_DIGITS + 1) - sizeNum] = str[i];
    }

}
