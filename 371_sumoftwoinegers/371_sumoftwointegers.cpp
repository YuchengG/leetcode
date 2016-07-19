// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

//   Example:
//   Given a = 1 and b = 2, return 3.

// Author: Songpeng Zu
// Time: July 14,2016

using namespace std;

// Solver 1
// Accepted
// From Discussion

class Solution {
public:
  int getSum(int a, int b) {
    int sum = 0;
    while(b != 0){
      sum = a^b;
      b = (a&b) << 1;
      a = sum;
    }
    return sum;
  }
};
