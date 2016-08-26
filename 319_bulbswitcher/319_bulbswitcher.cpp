// There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

//   Example:

//                                           Given n = 3.

//   At first, the three bulbs are [off, off, off].
//   After first round, the three bulbs are [on, on, on].
//   After second round, the three bulbs are [on, off, on].
//   After third round, the three bulbs are [on, off, off].

//   So you should return 1, because there is only one bulb is on.

// Author: Songpeng Zu
// Time: August 26, 2016

// Solver 1
// Time Limit

#include<vector>
using namespace std;

class Solution {
public:
  int countTimes(int index){
    // index >= 4
    int result = 0;
    for(int i=2;i<=index;++i){
      if(index % i == 0){result++;}
    }
    return result;
  }
  int bulbSwitch(int n) {
    if (n == 0) {return 0;}
    if(n <= 3) {return 1;}
    else{
      vector<int> state(n,1);
      for(int j=4;j<=n;++j){
        if (countTimes(j-1) % 2 == 0){
          state[j-1] = state[j-2] + 1;
        } else {
          state[j-1] = state[j-2];
        }
      }
      return state[n-1];
    }
  }
};


// Solver 2
// Not correct

class Solution {
public:
    int countTimes(int index){
        // index >= 4
        int result = 0;
        for(int i=2;i<=index;++i){
            if(index % i == 0){result++;}
        }
        return result;
    }
    int bulbSwitch(int n) {
        if (n == 0) {return 0;}
        if(n <= 3) {return 1;}
        else{
            vector<int> state(n,1);
            vector<int> countTimes(n,1);
            for(int j=4;j<=n;++j){

                int i = j-1;
                while((i>=2) && (j % i != 0)){i--;}
                if (i <= 1) {countTimes[j-1] = 1;}
                else if (i % (j/i) == 0 ) {countTimes[j-1] = countTimes[i-1] + 1;}
                else{
                    countTimes[j-1] = countTimes[i-1] + countTimes[i-1] + 1;
                }

                if (countTimes[j-1] % 2 == 0){
                    state[j-1] = state[j-2] + 1;
                } else {
                    state[j-1] = state[j-2];
                }
            }
            return state[n-1];
        }
    }
};

// Solver 3
// From Discussion
// Excellent explanation: https://discuss.leetcode.com/topic/31929/math-solution

#include<cmath>
class Solution {
public:
  int bulbSwitch(int n) {
    return sqrt(n);
  }
};
