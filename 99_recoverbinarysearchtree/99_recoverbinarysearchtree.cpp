// Two elements of a binary search tree (BST) are swapped by mistake.

//   Recover the tree without changing its structure.
//   Note:
//                                             A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

// Author: Songpeng Zu
// Time: July 28, 2016

#include<climits>

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
// From Discussion

class Solution {
public:
    void recoverTree(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == NULL || (root->val == min->val && root->val == max->val)) {return;}
        if(root->val > min->val && root->val < max->val){
            recoverTree(root->left,min,root);
            recoverTree(root->right,root, max);
        } else if(root->val < min->val){
            int tmp = min->val;
            min->val = root->val;
            root->val = tmp;
        } else{
            int tmp = max->val;
            max->val = root->val;
            root->val = tmp;
        }
    }
    bool isBST(TreeNode* root,long minValue, long maxValue){
        if(!root) {return true;}
        return (root->val > minValue && root->val < maxValue && isBST(root->left, minValue, root->val) && isBST(root->right,root->val,maxValue) );
    }
    void recoverTree(TreeNode* root) {
        TreeNode* Min = new TreeNode(INT_MIN);
        TreeNode* Max = new TreeNode(INT_MAX);
        while(!isBST(root, LLONG_MIN, LLONG_MAX)){
            recoverTree(root, Min, Max);
        }
    }
};
