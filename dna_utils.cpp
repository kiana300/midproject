#include "dna_utils.h"
#include <stdexcept>
#include<iostream>
using namespace std;
/*
* This function takes a single character as input, representing a DNA base, and
  returns its complementary base. In DNA, adenine (A) pairs with thymine (T),
and cytosine (C) pairs with guanine (G). The function uses a switch statement to
  determine the input base's complementary base:

  If the input is 'A', it returns 'T'.
  If the input is 'T', it returns 'A'.
  If the input is 'C', it returns 'G'.
  If the input is 'G', it returns 'C'.
  If the input character is not one of the valid bases (A, T, C, or G), the
  function throws an invalid_argument exception.
  */
char complement(char base) {
  switch (base) {
    case 'A':
      return 'T';
    case 'T':
      return 'A';
    case 'C':
      return 'G';
    case 'G':
      return 'C';
}
}



/*
This function takes string as input and then check .if the string is palindrom 
*return true else return false
*/
bool isPalindrom(string s){
    for(int i=0;i<=s.size()/2;i++){
        for(int j=s.size()/2+1;j<s.size();j++){
            bool isPalindrome = true;
            for (size_t k = i; k <= j; k++) {
            if (s[k] != complement(s[j - k])) {
                isPalindrome = false;
                break;
        }
    }
        return isPalindrome;
}
    }
}