// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

//   For example,
//   Given nums = [0, 1, 3] return 2.

//   Note:
//   Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

// Author: Songpeng Zu
// Time: August 25, 2016

// Solver 1
// Accepted

#include<vector>

using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int sum = 0;
    int length = nums.size();
    for(int i=0;i<length;++i){
      sum += nums[i];
    }
    return (length*(length+1)/2 - sum);
  }
};
