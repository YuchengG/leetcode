// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one
// sorted array.
//   Note: You may assume that nums1 has enough space (size that is greater or
//   equal to m + n) to hold additional elements from nums2. The number of elements
//   initialized in nums1 and nums2 are m and n respectively.

// Author: Songpeng Zu
// Time: July 1, 2016

#include<vector>
using namespace std;

// Solver 1 Runtime Error

// class Solution {
// public:
//   void moveback(vector<int>& nums1, int i, int moveStep){
//     if(moveStep >0 && nums1.size()>0 && i<nums1.size()){
//       for(int t=nums1.size()-1;t>=i;t--){
//         nums1[t+moveStep] = nums1[t];
//       }
//     }
//   } // end of function moveback

//   void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     if(m == 0){
//       for(int i=0;i<n;i++){nums1[i] = nums2[i];}
//     } // directly cope element from nums2.
//     else{
//       if(n>0){

//         int moveStep;
//         int i = 0;
//         int j = 0;
//         int t;
//         int moveStart;

//         while(i<m){
//           while(nums1[i] <= nums2[j]){
//             if(i == m-1) {
//               t = m;
//               while(j<n){nums1[t] = nums2[j];t++;j++;} // copy element from j to n-1 (nums2)
//             }
//             ++i;
//             if(i>=m){break;} // break current inner while.
//           } // end of while move i.
//           if(i >= m){break;} // i == m-1, end of function.

//           moveStep = 1;
//           t = i;
//           moveStart = j;
//           while(j+1<n && nums1[i] > nums2[j+1]){++j; ++moveStep;}
//           moveback(nums1, i, moveStep);

//           i = i + moveStep;
//           m = m + moveStep;
//           while(moveStart < j){nums1[t] = nums2[moveStart]; ++t;++moveStart;}
//         } // end of while i < m.
//       } // end of n >0
//     } // end of if else
//   } // end of function merge.
// };

// Solver 2
// From Discussion
// Add element from back to front.
class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
  {
    int r1 = m-1, r2 = n-1, r = m+n-1;
    while(r1>=0 && r2>=0)
      nums1[r--] = nums1[r1]>nums2[r2]? nums1[r1--] : nums2[r2--];
    while(r2 >= 0)
      nums1[r--] = nums2[r2--];
  }
};
