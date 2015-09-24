#include "compressedString.h"
#include <string.h>
#include <string>

using std::ostream;
using namespace std;

CompressedString::CompressedString(){

}

CompressedString::CompressedString(const char* str){    //Take the input string and compress it
    //Get input length
    int strSize = originalLength();

    //Set input to global
    for (int i=0; i<=strSize; i++) {
        *(origStr+i) = *(str+i);
    }

    //Create the array for the compressed string
    cmpStr = new char[strSize];

    int cnt = 1; //Set count to 1, if the letter exists once we need to count it

    //Cycle through input looking for similar chars
    for (int i=0; i<strSize; i++) {
        char prev = *str; //Set the current char value to prev
        str = str++; //Move the char forward
        if (prev == *str) { //If the previous value of the input equals the current value, it's a repeat so increase the count
            cnt++;
        } else { //Otherwise this is the first time we've seen it, we need to record the value in prev and note how many times we saw it
            *(cmpStr +i) = prev;
            *(cmpStr +i + 1) = cnt + '0'; //We have to convert count to a char, math does this for us
            cnt = 1; //Reset count to 1, if the letter exists once we need to count it
        }
    }
}

CompressedString::CompressedString(const CompressedString& other){

}

CompressedString::~CompressedString(){

}

void CompressedString::operator=(const CompressedString& other){

}

void CompressedString::operator+=(const CompressedString& other){

}

void CompressedString::operator+=(const char* str){

}

CompressedString CompressedString::operator+(const CompressedString& other) const{
   return CompressedString("");
}

CompressedString CompressedString::reverse() const{
   return CompressedString("");
}

void CompressedString::decompress(char* str, int size) const{
}

int CompressedString::length() const{
    int strSize = 0;
    char curr = *(cmpStr);
    while (curr != '\0') {
        strSize++;
        curr = *(cmpStr+1);
    }

   return strSize;
}

int CompressedString::originalLength() const{
    int strSize = 0;
    char curr = *(origStr);
    while (curr != '\0') {
        strSize++;
        curr = *(origStr+1);
    }

   return strSize;
}

double CompressedString::compressionRatio() const{
   return 0;
}

ostream& operator<<(ostream& outs, const CompressedString& source){
   return outs;
}

