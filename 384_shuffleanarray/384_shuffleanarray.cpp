Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();

// Author: Songpeng Zu
// Time: August 25, 2016

// Solver 1
// Accepted
#include<stdlib.h>
class Solution {
public:
    Solution(vector<int> nums) {
        store = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return store;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result;
        int curlen = store.size();
        if (curlen == 0) {return result;}
        if (curlen == 1) {return store;}
        vector<int> temp = store;
        while(curlen > 0){
            if (curlen == 1) {result.push_back(temp[0]);curlen--;}
            else {
                int index = rand() % curlen;
                result.push_back(temp[index]);
                temp.erase(temp.begin() + index);
                curlen--;
            }
        }
        return result;
    }
private:
    vector<int> store;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
