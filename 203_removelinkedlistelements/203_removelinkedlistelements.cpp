// Remove all elements from a linked list of integers that have value val.

// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//   Return: 1 --> 2 --> 3 --> 4 --> 5

// Author: Songpeng Zu
// Time: July 3, 2016

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
  ListNode* removeElements(ListNode* head, int val) {
    if(head == NULL) {return NULL;}
    else{
      if(head->next == NULL) {return (head->val == val) ? NULL : head;}
      ListNode* tmp = new ListNode(0);
      tmp->next = head;
      ListNode* pre = tmp;
      ListNode* cur = head;
      while(cur != NULL){
        if(cur->val == val){
          pre->next = cur->next;
          cur = cur->next;
        } else{
          pre = cur;
          cur = cur->next;
        }
      }
      return tmp->next;
    }
  }
};
