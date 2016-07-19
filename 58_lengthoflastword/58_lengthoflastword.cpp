// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

//   If the last word does not exist, return 0.

//   Note: A word is defined as a character sequence consists of non-space characters only.

//   For example,
//   Given s = "Hello World",
//   return 5.


// Author: Songpeng Zu
// Time: July 3, 2016

// Solver 1
// Accepted

#include<string>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    if(s.size() == 0) {return 0;}
    int i = s.size() - 1;
    while(i>=0){
      if(s[i] == ' '){
        s.pop_back();
        i--;
      }else{
        break;
      }
    }
    if(s.size() <= 1) {return s.size();}
    int result = 0;
    while(i>=0 && s[i] != ' '){
      result += 1;
      i--;
    }
    return result;
  }
};
