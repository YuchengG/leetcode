// Given a singly linked list, determine if it is a palindrome.

//   Follow up:
//   Could you do it in O(n) time and O(1) space?

using namespace std;

// Solver 1
// Accepted
// From Discussion

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    ListNode *slow = head , *fast=head ,*rev=NULL, *temp;
    while(fast && fast->next){
      fast = fast->next->next;
      temp = rev;
      rev = slow;
      slow = slow->next;
      rev->next = temp;
    }
    if(fast){
      slow = slow->next;
    }

    while(slow){
      if(slow->val != rev->val)  return false;
      slow = slow->next;
      rev = rev->next;
    }
    return rev == NULL;
  }
};
