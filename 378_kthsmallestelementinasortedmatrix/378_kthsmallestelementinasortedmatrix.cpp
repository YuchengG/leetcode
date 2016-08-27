// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

//   Note that it is the kth smallest element in the sorted order, not the kth distinct element.

//   Example:

//   matrix = [
//             [ 1,  5,  9],
//             [10, 11, 13],
//             [12, 13, 15]
//             ],
//   k = 8,

//   return 13.

//   Note:
//   You may assume k is always valid, 1 ≤ k ≤ n2.

// Author: Songpeng Zu
// Time: August 27, 2016

// Solver 1
// RunTime Error
#include<vector>
#include<pair>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rowNum = matrix.size();

        if (rowNum == 1 || k <= 1) {return matrix[0][0];}
        if (k == (rowNum*rowNum)) {return matrix[rowNum-1][rowNum-1];}

        //vector<pair<int,int> > rankPos;
        //rankPos.push_back(pair<int,int>(0,0));
        int prekRow = 0;
        int prekCol = 0;
        int tmpRow, tmpCol,t,s;
        for(int i=1;i<k;++i){
            //tmpRow = rankPos[i-1].first;
            //tmpCol = rankPos[i-1].second;
            tmpRow = prekRow;
            tmpCol = prekCol;
            int tmp = matrix[tmpRow][tmpCol];
            for(t=tmpRow;(tmpCol < (rowNum-1)) && (t>=1) && (matrix[t-1][tmpCol+1] >= tmp); --t){}
            for(s=tmpCol;(tmpRow < (rowNum-1)) && (s>=1) && (matrix[tmpRow+1][s-1] >= tmp);--s){}
            if (tmpCol == (rowNum-1)){
                //rankPos.push_back(pair<int,int>(tmpRow+1,s));
                prekRow = tmpRow+1;
                prekCol = s;
            } else if (tmpRow == (rowNum-1)){
                //rankPos.push_back(pair<int,int>(t,tmpCol+1));
                prekRow = t;
                prekCol = tmpCol+1;
            } else {
                if (matrix[tmpRow+1][s] < matrix[t][tmpCol+1]){
                    //rankPos.push_back(pair<int,int>(tmpRow+1,s));
                    prekRow = tmpRow+1;
                    prekCol = s;
                } else {
                    //rankPos.push_back(pair<int,int>(t,tmpCol+1));
                    prekRow = t;
                    prekCol = tmpCol + 1;
                }
            }
        }
        return matrix[prekRow][prekCol];
    }
};

// Solver 2
// From Discussion
// https://discuss.leetcode.com/topic/52865/my-solution-using-binary-search-in-c/9

#include<vector>
#include<pair>

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();

    int left = matrix[0][0];
    int right = matrix[n-1][n-1];

    while (left < right) {
      int midv = (left + right) / 2;

      int count = 0;  // number of elements no bigger than midv
      for (int i = 0; i < n; i++) {
        vector<int>& row = matrix[i];
        count += std::upper_bound(row.begin(), row.end(), midv) - row.begin();
      }

      if (count < k) {
        left = midv + 1;
      } else {
        right = midv;
      }
    }
    return left;
  }
};


// Solver 3
// From Discussion
// https://discuss.leetcode.com/topic/53126/o-n-from-paper-yes-o-rows/12
