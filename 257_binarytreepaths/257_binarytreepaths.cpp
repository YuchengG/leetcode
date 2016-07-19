// Given a binary tree, return all root-to-leaf paths.

//   For example, given the following binary tree:

//   1
//   /   \
//   2     3
//   \
//   5
//   All root-to-leaf paths are:
//   ["1->2->5", "1->3"]

// Author: Songpeng Zu
// Time: July 3, 2016

#include<string>
#include<vector>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Solver 1
// Accepted

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == NULL) {return result;}
        else{
            if(root->left == NULL && root->right == NULL){
                result.push_back(to_string(root->val));
                return result;
            }
            if(root->left != NULL) {
                vector<string> tmp = binaryTreePaths(root->left);
                for(int i=0;i<tmp.size();++i){
                    result.push_back(to_string(root->val) + "->" + tmp[i]);
                }
            }
            if(root->right != NULL){
                vector<string> tmp = binaryTreePaths(root->right);
                for(int i=0;i<tmp.size();++i){
                    result.push_back(to_string(root->val) + "->" + tmp[i]);
                }
            }
            return result;
        }
    }
};
