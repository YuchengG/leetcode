// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

//   For example,
//   Given 1->2->3->3->4->4->5, return 1->2->5.
//   Given 1->1->1->2->3, return 2->3.

// Author: Songpeng Zu
// Time: August 8, 2016

// Solver 1
// Accepted

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next == NULL) {return head;}
        ListNode* result = NULL;
        ListNode* tmp_first = head->next;
        ListNode* tmp_second = head;
        ListNode* add2result = result;
        ListNode* current;
        int count = 0;
        while(tmp_first != NULL){
            if (tmp_first->val == tmp_second->val){
                tmp_second = tmp_first;
                tmp_first = tmp_first->next;
                count++;
            } else{
                if(count == 0){
                    if(!result){
                        result = new ListNode(tmp_second->val);
                        current = result;
                        tmp_second = tmp_first;
                        tmp_first = tmp_first->next;
                    } else {
                        ListNode* tmpadd = new ListNode(tmp_second->val);
                        current->next = tmpadd;
                        current = tmpadd;
                        tmp_second = tmp_first;
                        tmp_first = tmp_first->next;
                    }
                } else{
                    tmp_second = tmp_first;
                    tmp_first = tmp_first->next;
                    count = 0;
                }
            }
        }
        if (count == 0){
            if(!result){
                result = new ListNode(tmp_second->val);
                return result;
            } else{
                ListNode* tmpadd = new ListNode(tmp_second->val);
                current->next = tmpadd;
                return result;
            }
        } else {
            return result;
        }
    }
};
