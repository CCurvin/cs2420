#include "compressedString.h"
#include <string.h>
#include <string>

using std::ostream;
using namespace std;

CompressedString::CompressedString(){
    this->origStr = " ";
    this->cmpStr = " ";
}

CompressedString::CompressedString(const char* str){    //Take the input string and compress it
    //Solve the chicken and egg issue
    origStr = str;

    //Get input length
    int strSize = originalLength();

    //Set input to global
/*  mobyfor (int i=0; i<=strSize; i++) {
        *(origStr+i) = *(str+i);
    } */

    //Create the array for the compressed string
    cmpStr = new char[strSize];

    int cnt = 0; //Set count to 0
    int pos = 0; //Set the Compressed String position
    char curr = ' ';
    char prev = ' ';

    //Cycle through input looking for similar chars
    for (int i=0; i<=strSize; i++) {
        curr = *(str+i); //Move the char forward
        if (i == 0) { //For the first round, we can't move left
            prev = *(str);
        } else {
            prev = *(str+i-1); //Set the current char value to prev
        }
        if (prev == curr) { //If the previous value of the input equals the current value, it's a repeat so increase the count
            cnt++;
        } else { //Otherwise this is the first time we've seen it, we need to record the value in prev and note how many times we saw it
            *(cmpStr+pos) = prev;
            cmpStrLength = ++pos;
            if (cnt > 1) {
                *(cmpStr+pos) = cnt + '0'; //We have to convert count to a char, math does this for us
                cmpStrLength = ++pos;
            }
            cnt = 1; //Reset count to 1, if the letter exists once we need to count it
        }
    }
}

CompressedString::CompressedString(const CompressedString& other){

    //CompressedString* dpcpy = new CompressedString;
    CompressedString* dpcpy;

    for (int i=0; i<=other.length(); i++) {
        *(dpcpy+i) = other.cmpStr;
    }

}

CompressedString::~CompressedString(){

delete [] cmpStr;

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

   return cmpStrLength;
}

int CompressedString::originalLength() const{
    int strSize = 0;
    char pos = *(origStr);
    for (int i=0; i<99999999; i++) { //Cop out method, break :D
//        while (pos != '\0') {
            strSize++;
            pos = *(origStr+i);
            if (pos == '\0') {
                strSize--;
                break;
            }
//        }
    }

   return strSize;
}

double CompressedString::compressionRatio() const{
   return 0;
}

ostream& operator<<(ostream& outs, const CompressedString& source){
   return outs;
}

