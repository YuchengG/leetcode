// Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

// Follow up:
// What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?

// Example:

// // Init a singly linked list [1,2,3].
// ListNode head = new ListNode(1);
// head.next = new ListNode(2);
// head.next.next = new ListNode(3);
// Solution solution = new Solution(head);

// // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
// solution.getRandom();

// Author: Songpeng Zu
// Time: August 25, 2016

// Solver 1
// Runtime Error

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include<stdlib.h>

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        store = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int length = listLength();
        if (length == 1) {return store->val;}
        int index = rand() % length;
        ListNode* tmp = store;
        int tmpIndex = 0;
        while(tmpIndex < index){
            tmp = tmp->next;
            tmpIndex++;
        }
        return tmp->val;
    }

    int listLength(){
        if (store == NULL) {return 0;} // this is error case.
        else {
            int result = 0;
            ListNode* tmp = store;
            while(!tmp){
                result++;
                tmp = tmp->next;
            }
            return result;
        }
    }
private:
    ListNode* store;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */


// Solver 2
// From Discussion

class Solution {
private:
  ListNode* head;
public:
  /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) {
    this->head = head;
  }

  /** Returns a random node's value. */
  int getRandom() {
    int res = head->val;
    ListNode* node = head->next;
    int i = 2;
    while(node){
      int j = rand()%i;
      if(j==0)
        res = node->val;
      i++;
      node = node->next;
    }
    return res;
  }
};
