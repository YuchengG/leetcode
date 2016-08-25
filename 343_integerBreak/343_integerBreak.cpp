// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

//   For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

//                                                     Note: You may assume that n is not less than 2 and not larger than 58.


// Author: Songpeng Zu
// Time: 2016-8-25

#include<vector>

using namespace std;

// Solution 1
// Time Limit Exceeded

// class Solution {
// public:
//   int integerBreak(int n) {
//     if (n == 2 || n == 1) {return 1;}
//     else if (n == 3) {return 2;}
//     else{
//       int result = 1;
//       int stopdex = n>>1;
//       for(int i = 1;i <= stopdex;++i){
//         int t1 = integerBreak(i);
//         int t2 = integerBreak(n-i);
//         int left = (t1 < i ) ? i : t1;
//         int right = (t2 < (n-i)) ? (n-i) : t2;
//         int temp = left*right;
//         result = (result < temp) ? temp : result;
//       }
//       return result;
//     }
//   }
// };


// Solution 2
// Accepted

class Solution {
public:
  void integerBreak(int n, vector<int>& preResult){
    // n >= 4;
    int result = 1;
    int stopdex = n/2;
    for(int i = 1;i <= stopdex;++i){
      int t1 = preResult[i-1];
      int t2 = preResult[n-i-1];
      int left = (t1 < i ) ? i : t1;
      int right = (t2 < (n-i)) ? (n-i) : t2;
      int temp = left*right;
      result = (result < temp) ? temp : result;
    }
    preResult[n-1] = result;
    return;
  }
  int integerBreak(int n) {
    if (n == 2 || n == 1) {return 1;}
    else if (n == 3) {return 2;}
    else{
      vector<int> tmpResult(n,0);
      tmpResult[0] = 1;
      tmpResult[1] = 1;
      tmpResult[2] = 2;
      for(int i = 4;i<=n;++i){
        integerBreak(i,tmpResult);
      }
      return tmpResult[n-1];
    }
  }
};
