// Given an array of integers, every element appears twice except for one. Find that single one.

//   Note:
//   Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Author: Songpeng Zu
// Time: July 14, 2016

#include<vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int t = 0;
    for(int i=0;i<nums.size();++i){
      t = t^nums[i];
    }
    return t;
  }
};
