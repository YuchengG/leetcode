// 347. Top K Frequent Elements

// Total Accepted: 21820
// Total Submissions: 50423
// Difficulty: Medium

// Given a non-empty array of integers, return the k most frequent elements.

//   For example,
//   Given [1,1,1,2,2,3] and k = 2, return [1,2].

//   Note:

//   You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//   Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

// Author: Songpeng Zu
// Time: July 25, 2016

#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>


using namespace std;

// Solver 1
// Accepted

#include<map>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<size_t> sortIndex(const vector<int>& v){
        //if (v.size() == 1) {return vector<int>(1,0);}
        vector<size_t> result(v.size());
        iota(result.begin(),result.end(),0);
        sort(result.begin(),result.end(),[&v](size_t indA, size_t indB){return v[indA] < v[indB];});
        return result;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        if(k == 0) {return result;}
        if(nums.size()==1){return nums;}
        map<int, int> freq;
        for(int i=0;i<nums.size();++i){
            if(freq.find(nums[i]) != freq.end()){
                freq[nums[i]] = freq[nums[i]] + 1;
            } else {
                freq[nums[i]] = 1;
            }
        }
        vector<int> storefreq;
        vector<int> storekey;
        map<int,int>::iterator it;
        for(it=freq.begin();it!=freq.end();++it){
            storefreq.push_back(it->second);
            storekey.push_back(it->first);
        }
        vector<size_t> sortfreqIndex = sortIndex(storefreq);
        int j = storefreq.size() - 1;
        while(j >= (int(storefreq.size()) - k)){
            result.push_back(storekey[sortfreqIndex[j--]]);
        }
        return result;
    }
};
