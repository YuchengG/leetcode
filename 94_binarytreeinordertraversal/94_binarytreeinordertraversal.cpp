// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree [1,null,2,3],

//    1
//     \
//      2
//     /
//    3

// return [1,3,2].

// Note: Recursive solution is trivial, could you do it iteratively?

// Author: Songpeng Zu
// Time: August 26, 2016

// Solver 1
// Accepted
// Recursive

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
  void inorderTraversal(TreeNode* root, vector<int>& result){
    if (root == NULL){return;}
    else{
      if(root->left != NULL) {inorderTraversal(root->left, result);}
      result.push_back(root->val);
      if (root->right != NULL) {inorderTraversal(root->right, result);}
      return;
    }
  }
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) {return result;}
    else{
      inorderTraversal(root, result);
      return result;
    }
  }
};

// Solver 2
// Iterative

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<stack>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {return result;}
        else{
            stack<bool> visitState;
            stack<TreeNode*> visitNode;
            TreeNode* tmp = root;
            visitState.push(false);
            visitNode.push(tmp);
            bool curState = false;
            while(!visitNode.empty()){
                curState = visitState.top();
                visitState.pop();
                tmp = visitNode.top();
                visitNode.pop();
                if (curState){
                    result.push_back(tmp->val);
                } else {
                    if(tmp->right != NULL) {
                        visitNode.push(tmp->right);
                        visitState.push(false);
                    }
                    visitNode.push(tmp);
                    visitState.push(true);
                    if (tmp->left != NULL) {
                        visitNode.push(tmp->left);
                        visitState.push(false);
                    }
                } // end of if-else
            } // end of while
            return result;
        }
    }
};
