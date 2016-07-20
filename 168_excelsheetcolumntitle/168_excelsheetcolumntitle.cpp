// Given a positive integer, return its corresponding column title as appear in an Excel sheet.

//   For example:

//   1 -> A
//   2 -> B
//   3 -> C
//   ...
//   26 -> Z
//   27 -> AA
//   28 -> AB

// Author: Songpeng Zu
// Time: July 20, 2016

#include<string>
#include<iostream>

using namespace std;

// Solver 1
// Wrong Answer

// class Solution {
// public:
//   string convertToTitle(int n) {
//     string result;
//     if (n == 0) {return result;}
//     //if (n <= 26) {result.push_back('A' + (n-1)%26); return result;}
//     //int t = 0;
//     while(n>=1){
//       cout<<"Current N is " << n << endl;
//       if(n <= 26) {result.insert(0,1,'A' + (n-1)%26);cout<<result<<endl;return result;}
//       result.insert(0,1,'A' + (n-1)%26);
//       //++t;
//       //result.push_back('A' + (n-1)%26);
//       n = n / 27;
//     }
//     cout<<result<<endl;
//     return result;
//   }
// };

// Solver 2
// Discussion

#include<string>
using namespace std;

class Solution {
public:
  string convertToTitle(int n) {
    string res="";
    while(n>0){
      res=char('A'+(n-1)%26)+res;
      n=(n-1)/26;
    }
    return res;
  }
};
