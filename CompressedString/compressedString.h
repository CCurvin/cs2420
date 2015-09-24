#ifndef COMPRESSED_STRING_H
#define COMPRESSED_STRING_H

#include <iostream>

class CompressedString{

   public:
      CompressedString();
      CompressedString(const char* str);
      CompressedString(const CompressedString& other);
      ~CompressedString();
      void operator=(const CompressedString& other);
      void operator+=(const CompressedString& other);
      void operator+=(const char* str);
      CompressedString operator+(const CompressedString& other) const;
      CompressedString reverse() const;
      void decompress(char* str, int size) const;
      int length() const;
      int originalLength() const;
      double compressionRatio() const;
      friend std::ostream& operator<<(std::ostream& outs, const CompressedString& source);

   private:
      char* cmpStr; //Our compressed string
      int strSize;

};


#endif
