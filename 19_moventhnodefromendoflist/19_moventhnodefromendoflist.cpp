// Given a linked list, remove the nth node from the end of list and return its head.

//   For example,

//   Given linked list: 1->2->3->4->5, and n = 2.

//   After removing the second node from the end, the linked list becomes 1->2->3->5.

//   Note:
//   Given n will always be valid.
//   Try to do this in one pass.

// Author: Songpeng Zu
// Time: July 2, 2016

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Solver 1
// Accepted

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* tmp = new ListNode(0);
    tmp->next = head;
    ListNode* pre = tmp;
    ListNode* aft = head;
    while(n>0){
      aft = aft->next;
      n--;
    }
    while(aft != NULL){
      aft = aft->next;
      pre = pre->next;
    }
    pre->next = pre->next->next;
    return tmp->next;
  }
};
