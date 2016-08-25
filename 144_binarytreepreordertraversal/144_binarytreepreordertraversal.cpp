/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// Author: Songpeng Zu
// Time: August 26, 2016

// Solver 1
// Accepted


#include<stack>
#include<vector>

using namespace std;


class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) {return result;}
    else{
      stack<TreeNode*> visitNode;
      TreeNode* tmp = root;
      visitNode.push(root);
      while(!visitNode.empty()){
        tmp = visitNode.top();
        visitNode.pop();
        result.push_back(tmp->val);
        if (tmp->right != NULL){
          visitNode.push(tmp->right);
        }
        if (tmp->left != NULL) {
          visitNode.push(tmp->left);
        }
      }
      return result;
    }
  }
};
