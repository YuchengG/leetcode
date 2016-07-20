// Rotate an array of n elements to the right by k steps.

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

//   Note:
//   Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

//   [show hint]
//   Hint:
//   Could you do it in-place with O(1) extra space?

//                  Related problem: Reverse Words in a String II

// Author: Songpeng Zu
// Time: July 20, 2016

#include<vector>
#include<algorithm>
using namespace std;

// Solver 1
// Time Limit Exceeded

// class Solution {
// public:
//   void rotate(vector<int>& nums, int k) {
//     if(k>0 && nums.size()>1){
//       int temp,i;
//       k = k%nums.size();
//       while(k>=1){
//         i = nums.size()-1;
//         int temp = nums[i];
//         while(i>=1){
//           nums[i] = nums[--i];
//         }
//         nums[0] = temp;
//         --k;
//       }
//     }
//   }
// };


// Solver 2
// From Discussion.

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    if(k>0 && nums.size()>1){
      k = k%nums.size();
      vector<int>::iterator iter=nums.begin();
      int move = 0;
      while(move < nums.size()-k){
        iter++;
        ++move;
      }
      reverse(nums.begin(),iter);
      reverse(iter, nums.end());
      reverse(nums.begin(),nums.end());
    }
  }
};
