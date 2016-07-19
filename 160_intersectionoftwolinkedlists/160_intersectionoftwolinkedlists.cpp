// Write a program to find the node at which the intersection of two singly linked lists begins.
// Notes:
// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns.
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.

// Author: Songpeng Zu
// Time: July 1, 2016

#include<map>
using namespace std;

// Solver 1
// Accepted

class Solution {
public:
  ListNode *reverseLink(ListNode* head){
    if(head == NULL) {return NULL;}
    ListNode* pre = head;
    ListNode* cur = head->next;
    ListNode* t;
    while(cur != NULL){
      t = cur->next;
      cur->next = pre;
      pre = t;
      if(t == NULL){return cur;}
      cur = t->next;
    }
    return pre;
  }
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) {return NULL;}
    if (headA == headB) {return headA;}
    map<ListNode*, bool> record;
    ListNode* tA = headA;
    while(tA != NULL){
      record.insert(pair<ListNode*,bool>(tA, true));
      tA = tA->next;
    }
    ListNode* tB = headB;
    while(tB != NULL){
      if(record.find(tB) != record.end()){return tB;}
      else{tB = tB->next;}
    }
    return false;
  }
};
