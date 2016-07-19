// Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

//   Solve it without division and in O(n).

//   For example, given [1,2,3,4], return [24,12,8,6].

//   Follow up:
//   Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

// Author: Songpeng Zu
// Time: July 14, 2016

#include<vector>
using namespace std;

// Solve 1
// Accepted
// From Discussion

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int len=nums.size();
    vector<int> left(len, 1);
    vector<int> right(len, 1);
    vector<int> result(len, 0);
    for(int i=1; i<len; i++)  left[i]=left[i-1]*nums[i-1];
    for(int i=len-2; i>=0; i--)  right[i]=right[i+1]*nums[i+1];
    for(int i=0; i<len; i++) result[i]=left[i]*right[i];
    return result;
  }
};


// Solver 2
// Accepted
// From Discussion

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    int left=1, right=1;
    vector<int> result(n, 1);
    for(int i=0; i<n; i++){
      result[i]*=left;
      result[n-1-i]*=right;
      left*=nums[i];
      right*=nums[n-1-i];
    }
    return result;
  }
};
