// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

//   The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

//   You may assume that each input would have exactly one solution.

//   Input: numbers={2, 7, 11, 15}, target=9
//   Output: index1=1, index2=2

// Author: Songpeng Zu
// Time: 2016-08-25

#include<vector>

using namespace std;

// Solver 1
// Accepted

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    if (numbers.size() < 2) {return result;}
    int left = 0;
    int right = numbers.size() - 1;
    while(left < right && result.empty()){
      if (numbers[left] + numbers[right] < target) { left++;}
      else if (numbers[left] + numbers[right] > target) {right--;}
      else{
        result.push_back(left+1);
        result.push_back(right+1);
      }
    }
    return result;
  }
};
