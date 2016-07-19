// You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

//   Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

//   You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.


// Author: Songpeng Zu
// Time: July 20, 2016

using namespace std;

// Solver 1
// Accepted

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int begin, int end){
    if(begin >= end) {return isBadVersion(begin) ? begin : 0;}
    else{
      if(isBadVersion(begin + (end-begin)/2)){
        return firstBadVersion(begin, begin + (end-begin)/2);
      } else {
        return firstBadVersion(begin+(end-begin)/2+1, end);
      }
    }
  }
  int firstBadVersion(int n) {
    if(n==1){return isBadVersion(n) ? n : 0;}
    if(isBadVersion(n/2)) {
      return firstBadVersion(1, n/2);
    } else {
      return firstBadVersion(n/2+1, n);
    }
  }
};
