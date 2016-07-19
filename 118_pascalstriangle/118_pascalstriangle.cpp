// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]


// Author: Songpeng Zu
// Time: July 14, 2016

#include<vector>
using namespace std;

// Solver 1
// Accepted


class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int> > result;
    if(numRows <= 0 ) {return result;}
    vector<int> tmp;
    result.push_back(vector<int>(1,1));
    if(numRows == 1) {return result;}
    for(int i=1;i<numRows;i++){
      vector<int> cur(i+1,0);
      tmp.push_back(0);
      for(int j=0;j<result[i-1].size();++j){
        tmp.push_back(result[i-1][j]);
      }
      tmp.push_back(0);
      for(int t=0;t<cur.size();++t){
        cur[t] = tmp[t]+tmp[t+1];
      }
      result.push_back(cur);
      tmp.clear();
    }
    return result;
  }
};
