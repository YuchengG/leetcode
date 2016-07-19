// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

//   For example:

//   Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

//   Note:

//   The order of the result is not important. So in the above example, [5, 3] is also correct.
//   Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?


// Author: Songpeng Zu
// Time: July 14, 2016

#include<vector>
using namespace std;

// Solver 1
// Accepted
// From Discussion

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int t1 = 0;
    int t2 = 0;
    int temp = 0;
    for(int i=0;i<nums.size();++i){
      temp = temp^nums[i];
    }
    int j = 1;
    for(;j<=sizeof(int)*8;++j){
      if((temp>>j)&1 == 1){
        break;
      }
    }
    for(int i=0;i<nums.size();++i){
      if((nums[i]>>j)&1 == 1){
        t1 = t1^nums[i];
      } else{
        t2 = t2^nums[i];
      }
    }
    vector<int> result;
    result.push_back(t1);
    result.push_back(t2);
    return result;
  }
};
