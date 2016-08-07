// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//   Do not allocate extra space for another array, you must do this in place with constant memory.
//   For example,
//   Given input array nums = [1,1,2],
//   Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

// Author: Songpeng Zu
// Time: August 7, 2016

#include<vector>

using namespace std;

// Solver 1
// Time Limit Exceeded

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if(nums.size() < 1) {return 0;}
//         int repeatNum = 0;
//         int i;
//         while(true){
//             if (nums.size() == 1) {return nums.size();}
//             for(i=1;i<nums.size();i++){
//                 if(nums[i] == nums[i-1]){
//                     repeatNum += 1;
//                 } else{
//                     if(repeatNum >0) {break;}
//                 } // end of if-else
//             } // end of for
//             if( i == nums.size() ){
//                 if (repeatNum == 0) {return nums.size();} // No repreats.
//                 else { // only one unique.
//                     for(int t=0;t<repeatNum;++t){
//                         nums.pop_back();
//                     }
//                     return nums.size();
//                 }
//             }
//             for(int j=i;j<nums.size();j++){
//                 nums[j-repeatNum] = nums[j];
//             }
//             for(int t=0;t<repeatNum;t++){
//                 nums.pop_back();
//             }
//             repeatNum = 0;
//         } // end of while
//     }
// };

// Solver 2
// Time Limit Exceeded

// class Solution {
// public:
//     int getRepeatNum(vector<int>& nums, int curPos){
//         if(curPos == 0) {return 0;}
//         else{
//             int result = 0;
//             for(int i=curPos;i>=1;--i){
//                 if(nums[i-1] == nums[i]){
//                     result += 1;
//                 } else {
//                     return result;
//                 }
//             }
//             return result;
//         }
//     }
//     void removeLastNEle(vector<int>& nums, int repeatNum){
//         if (repeatNum == 0) {return;}
//         else{
//             for(int t=0;t<repeatNum;++t){
//                 nums.pop_back();
//             }
//             return;
//         }
//     }
//     void moveforward(vector<int>& nums, int curPos, int repeatNum){
//         if (repeatNum == 0) {return;}
//         else if (curPos < (nums.size()-1) ){
//             for(int j=curPos+1;j<nums.size();++j){
//                 nums[j-repeatNum] = nums[j];
//             }
//             removeLastNEle(nums,repeatNum);
//             return;
//         } else {
//             removeLastNEle(nums,repeatNum);
//             return;
//         }
//     }
//     int removeDuplicates(vector<int>& nums) {
//         if (nums.size() <= 1) {return nums.size();}
//         int i = nums.size() - 1;
//         int repeatNum = 0;
//         while(true){
//             if(i==0) {return nums.size();}
//             repeatNum = getRepeatNum(nums,i);
//             if(repeatNum > 0) {
//                 if ( (i-repeatNum) == 0){
//                     moveforward(nums, i, repeatNum);
//                     return nums.size();
//                 }
//                 moveforward(nums,i,repeatNum);
//                 i = i - repeatNum;
//             } else {
//                 if(i==0) {return nums.size();}
//                 else{--i;}
//             }
//         }
//         return nums.size();
//     }
// };

// Solver 3
// From Discussion

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int count = 0;
    for(int i = 1; i < nums.size(); i++){
      if(nums[i] == nums[i-1]) count++;
      else nums[i-count] = nums[i];
    }
    return nums.size()-count;
  }
};
