//Given an array of integers and an integer k, find out whether there are two
//distinct indices i and j in the array such that nums[i] = nums[j] and the
//difference between i and j is at most k.

// Author: Songpeng Zu
// Time: Jun 30, 2016

#include <vector>
using namespace std;

// Solver 1
// Time Limit Exceeded

// class Solution {
// public:
//   bool containsNearbyDuplicate(vector<int>& nums, int k) {
//     if(nums.size() == 0) {return false;}
//     if(k == 0) {return false;}
//     int j;
//     for(int i=0;i<nums.size()-1;++i){
//       j = i+1;
//       while( j-i <=k && j<nums.size()){
//         if(nums[i] == nums[j]) {return true;}
//         j++;
//       }
//     }
//     return false;
//   }
// };


// Solver 2
// Time Limit Exceeded

// class Solution {
// public:
//   bool containsNearbyDuplicate(vector<int>& nums, int k){
//     if(nums.size() == 0){return false;}
//     if(k == 0){return false;}
//     vector<char> record(nums.size(), 'b');
//     int i = 0;
//     int j;
//     int dist;
//     int pre;
//     while(i <nums.size() && record[i] == 'b'){
//       record[i] = 'w';
//       j = i+1;
//       dist = 0;
//       pre = i;
//       while(j<nums.size() && record[j] == 'b'){
//         if(nums[i] == nums[j]){
//           if(dist == 0){dist = j-i;}
//           else{dist = (dist > (j-pre))? (j-pre) : dist;}
//           if(dist <= k) {return true;}
//           record[j] = 'w';
//           pre = j;
//         }
//         ++j;
//       }
//       ++i;
//     }
//     return false;
//   }
// };

// Solver 3 From Discussion
// Accepted
// Note: record element every step, and use hash to quickly search.

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k){
    if(nums.size() == 0){return false;}
    if(k == 0){return false;}
    map<int,int> record;
    for(int i=0;i<nums.size();++i){
      if(record.find(nums[i]) != record.end()){
        if( i - record[nums[i]] <=k){return true;}
        else{record[nums[i]] = i;}
      }
      else{
        record.insert(pair<int,int>(nums[i],i));
      }
    }
    return false;
  }
};
