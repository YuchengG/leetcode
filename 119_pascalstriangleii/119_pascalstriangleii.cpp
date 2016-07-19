
// Given an index k, return the kth row of the Pascal's triangle.

// For example, given k = 3,
// Return [1,3,3,1].

// Note:
// Could you optimize your algorithm to use only O(k) extra space?

// Author: Songpeng Zu
// Time: July 14, 2016

#include<vector>
using namespace std;

// Solver 1
// Accepted

class Solution {
public:
  int nChoosek( int n, int k )
  {
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    double result = n;
    for( int i = 2; i <= k; ++i ) {
      result /=i; // note: if firstly multiple, then it may overflow.
      result *= (n-i+1);
    }
    return (result - (int) result >= 0.5) ? (int) result +1 : (int) result ;
  }
  vector<int> getRow(int rowIndex) {
    if (rowIndex < 0) {return vector<int>();}
    if (rowIndex == 0) {return vector<int>(1,1);}
    vector<int> result(rowIndex+1,0);
    for(int i=0;i<result.size();++i){
      result[i] = nChoosek(rowIndex,i);
    }
    return result;
  }
};
