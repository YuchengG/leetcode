// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

using namespace std;

// Author: Songpeng Zu
// Time: July 26, 2016

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {return NULL;}
        if (head->next == NULL) {return new TreeNode(head->val);}
        ListNode* middle = head;
        ListNode* tmp = head;
        while(tmp != NULL && tmp->next != NULL){
            tmp = tmp->next->next;
            middle = middle->next;
        }
        TreeNode* root = new TreeNode(middle->val);
        ListNode* right = middle->next;
        ListNode* leftlast = head;
        while(leftlast->next != middle) {
            leftlast = leftlast->next;
        }
        leftlast->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(right);
        return root;
    }
};
