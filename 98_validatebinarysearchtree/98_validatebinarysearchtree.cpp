// Given a binary tree, determine if it is a valid binary search tree (BST).

//   Assume a BST is defined as follows:

//   The left subtree of a node contains only nodes with keys less than the node's key.
//     The right subtree of a node contains only nodes with keys greater than the node's key.
//   Both the left and right subtrees must also be binary search trees.

//   Example 1:

//   2
//   / \
//   1   3

//   Binary tree [2,1,3], return true.

//   Example 2:

//   1
//   / \
//   2   3

//   Binary tree [1,2,3], return false.



// Author: Songpeng Zu
// Time: July 27, 2016

#include<stack>
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
    bool isrightBST(TreeNode* root){
        if (root == NULL || root->right == NULL) {return true;}
        stack<TreeNode*> pool;
        pool.push(root->right);
        TreeNode* tmp;
        while(!pool.empty()){
            tmp = pool.top();
            pool.pop();
            if (tmp->val <= root->val) {return false;}
            if(tmp->left != NULL) {pool.push(tmp->left);}
            if(tmp->right != NULL) {pool.push(tmp->right);}
        }
        return true;
    }

    bool isleftBST(TreeNode* root){
        if (root == NULL || root->left == NULL) {return true;}
        stack<TreeNode*> pool;
        pool.push(root->left);
        TreeNode* tmp;
        while(!pool.empty()){
            tmp = pool.top();
            pool.pop();
            if (tmp->val >= root->val) {return false;}
            if(tmp->left != NULL) {pool.push(tmp->left);}
            if(tmp->right != NULL) {pool.push(tmp->right);}
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {return true;}
        if (!isleftBST(root)) {return false;}
        if (!isrightBST(root)) {return false;}
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
