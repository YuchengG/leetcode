// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

//   Note:
//   You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
// Hint:

//     Try to utilize the property of a BST.
//     What if you could modify the BST node's structure?
//     The optimal runtime complexity is O(height of BST).

// Author: Songpeng Zu
// Time: August 26, 2016

// Solver 1
// Wrong Answer

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int Inorder(TreeNode* root, int times, int& count){
    if (root->left != NULL){
      Inorder(root->left,times, count);
    } else{
      count++;
      if (count == times){return root->val;}
      else{
        if (root->right != NULL){Inorder(root->right,times, count);}

      }
    }
  }
  int kthSmallest(TreeNode* root, int k) {
    if (root->left == NULL && root->right == NULL) {return root->val;}
    int count = 0;
    return Inorder(root, k, count);
  }
};

// Solver 2
// From Discussion
// https://discuss.leetcode.com/topic/17573/4-lines-in-c/2

int kthSmallest(TreeNode* root, int& k) {
  if (root) {
    int x = kthSmallest(root->left, k);
    return !k ? x : !--k ? root->val : kthSmallest(root->right, k);
  }
}
