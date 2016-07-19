// Reverse digits of an integer.

// Example1: x = 123, return 321
//   Example2: x = -123, return -321

//   Have you thought about this?

//   Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

//   If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

// Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

// Update (2014-11-10):
// Test cases had been added to test the overflow behavior.

// Author: Songpeng Zu
// Time: July 11, 2016

#include<climits>
#include<cmath>
#include<string>

using namespace std;

// Solver 1
// Wrong Answer at -2147483412, which returned 0 in my method.

// class Solution {
// public:
//     bool isGreater(string x, string y){
//         if(x.size() < y.size()) {return false;}
//         if(x.size() > y.size()) {return true;}
//         for(int i=0; i<x.size();++i){
//             if(x[i] > y[i]) {return true;}
//         }
//         return false;
//     }
//     string reverseStr(string x){
//         if (x.size() < 1) {return x;}
//         string result;
//         for(int i=x.size()-1;i>=0;--i){
//             result.push_back(x[i]);
//         }

//         return result;
//     }
//     int reverse(int x) {
//         if(x == 0) {return 0;}
//         if(x<0){
//             string pre = reverseStr(to_string(x));
//             string iMax = reverseStr(to_string(INT_MIN));
//             pre.pop_back();
//             iMax.pop_back();
//             string iMin = reverseStr(iMax);
//             return isGreater(pre,iMin) ? 0 : stoi(pre.insert(0,"-"));
//         }
//         else{
//             string pre = to_string(x);
//             string iMax =  to_string(INT_MAX);
//             return isGreater(reverseStr(pre), iMax) ? 0 : stoi(reverseStr(pre));
//         }
//     }
// };


// Solver 2
// Accepted
// From Discussion

class Solution {
public:
  int reverse(int x) {
    int flag=0;
    if(x<0)
      {
        x=-x;
        flag=1;
      }
    long long int ans=0;
    while(x>0)
      {
        ans=ans*10+(x%10);
        x/=10;
      }
    if(ans>INT_MAX)return 0;
    if(flag==1)ans=-ans;
    return ans;
  }
};
