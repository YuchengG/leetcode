// Description:

// Count the number of prime numbers less than a non-negative number, n.

// Author: Songpeng Zu
// Time: July 10, 2016

#include<vector>

using namespace std;

// Solver 1
// Accepted

class Solution {
public:
  int countPrimes(int n) {
    if (n <= 1) { return 0;}
    vector<bool> PrimesLabel(n,false);
    int result = 0;
    int j;
    for(int i=2;i<n;i++){
      j=2;
      if(!PrimesLabel[i]){
        ++result;
        while(j*i<n){
          PrimesLabel[j*i] = true;
          ++j;
        }
      }
    }
    return result;
  }
};
