// Sort a linked list in O(n log n) time using constant space complexity.

// Author: Songpeng Zu
// Time: August 8, 2016

using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Solver 1
// Time Limit Exceeded.

// class Solution {
// public:
//     ListNode* beforeLastList(ListNode* head, ListNode* last){
//         if(head == NULL || head->next == NULL) {
//             return head;
//         }
//         ListNode* result = head;
//         while(result->next != last){
//             result = result->next;
//         }
//         return result;
//     }
//     ListNode* partitionList(ListNode* head, ListNode* startL, ListNode* endL){
//         if (head == NULL || head->next == NULL) {return head;}
//         int pivot = startL->val;
//         ListNode* result = startL;
//         ListNode* movePoint = startL;
//         while(true){
//             if (pivot > movePoint->val){
//                 result->val = movePoint->val;
//                 movePoint->val = pivot;
//                 result = result->next;
//             }
//             movePoint = movePoint->next;
//             if (movePoint == endL) {
//                 if (pivot > movePoint->val){
//                     result->val = movePoint->val;
//                     movePoint->val = pivot;
//                 }
//                 return result;
//             }
//         }
//     }
//     void quickSortList(ListNode* head, ListNode* startL, ListNode* endL){
//         if (startL == endL) {return;}
//         else{
//             ListNode* posL = partitionList(head, startL, endL);
//             if (posL != endL) {
//                 quickSortList(head,startL,posL);
//                 quickSortList(head,posL->next, endL);
//                 return;
//             } else {
//                 //quickSortList(head,startL->next,endL);
//                 ListNode* changeEndL = beforeLastList(startL,endL);
//                 quickSortList(head,startL, changeEndL);
//                 return;
//             }
//         }
//     }
//     ListNode* sortList(ListNode* head) {
//         if (head == NULL || head->next == NULL) {return head;}
//         else{
//             ListNode* last = beforeLastList(head, NULL);
//             quickSortList(head, head, last);
//             return head;
//         }
//     }
// };class Solution {
// public:
//     ListNode* beforeLastList(ListNode* head,ListNode* last){
//         if (head == last) {return NULL;}
//         ListNode* result = head;
//         while(result->next != last){
//             result = result->next;
//         }
//         return result;
//     }
//     ListNode* partitionList(ListNode* head, ListNode* startL, ListNode* endL){
//         if (head == NULL || head->next == NULL) {return head;}
//         int pivot = startL->val;
//         ListNode* result = startL;
//         ListNode* movePoint = startL;
//         while(true){
//             if (movePoint == endL) {
//                 if (pivot > movePoint->val){
//                     int tmp = result->val;
//                     result->val = movePoint->val;
//                     movePoint->val = tmp;
//                     result = result->next;
//                 }
//                 return result;
//             }
//             if (pivot > movePoint->val){
//                 int tmp = result->val;
//                 result->val = movePoint->val;
//                 movePoint->val = tmp;
//                 result = result->next;
//             }
//             movePoint = movePoint->next;
//         }
//     }
//     void quickSortList(ListNode* head, ListNode* startL, ListNode* endL){
//         if (startL == endL) {return;}
//         else{
//             ListNode* posL = partitionList(head, startL, endL);
//             if (posL != endL) {
//                 if (posL == startL) {
//                     quickSortList(head,posL->next,endL);
//                     return;
//                 }
//                 ListNode* changeEndL = beforeLastList(startL,posL);
//                 quickSortList(head,startL,changeEndL);
//                 quickSortList(head,posL, endL);
//                 return;
//             } else {
//                 //quickSortList(head,startL->next,endL);
//                 ListNode* changeEndL = beforeLastList(startL,endL);
//                 quickSortList(head,startL, changeEndL);
//                 return;
//             }
//         }
//     }
//     ListNode* sortList(ListNode* head) {
//         if (head == NULL || head->next == NULL) {return head;}
//         else{
//             ListNode* last = beforeLastList(head,NULL);
//             quickSortList(head, head, last);
//             return head;
//         }
//     }
// };


// Solver 2
// From Discussion

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //divide the list into two parts
        fast = slow->next;
        slow->next = NULL;

        return merge(sortList(head), sortList(fast));
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dump(0);
        ListNode* cur = &dump;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }

            cur = cur->next;
        }

        if (l1 != NULL)
            cur->next = l1;
        else
            cur->next = l2;

        return dump.next;
    }
};

// Solver 3
// From Discussion
/**
 * Merge sort use bottom-up policy,
 * so Space Complexity is O(1)
 * Time Complexity is O(NlgN)
 * stable sort
*/
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if(!head || !(head->next)) return head;

    //get the linked list's length
    ListNode* cur = head;
    int length = 0;
    while(cur){
      length++;
      cur = cur->next;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode *left, *right, *tail;
    for(int step = 1; step < length; step <<= 1){
      cur = dummy.next;
      tail = &dummy;
      while(cur){
        left = cur;
        right = split(left, step);
        cur = split(right,step);
        tail = merge(left, right, tail);
      }
    }
    return dummy.next;
  }
private:
  /**
   * Divide the linked list into two lists,
     * while the first list contains first n ndoes
   * return the second list's head
   */
  ListNode* split(ListNode *head, int n){
    //if(!head) return NULL;
    for(int i = 1; head && i < n; i++) head = head->next;

    if(!head) return NULL;
    ListNode *second = head->next;
    head->next = NULL;
    return second;
  }
  /**
    * merge the two sorted linked list l1 and l2,
    * then append the merged sorted linked list to the node head
    * return the tail of the merged sorted linked list
   */
  ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
    ListNode *cur = head;
    while(l1 && l2){
      if(l1->val > l2->val){
        cur->next = l2;
        cur = l2;
        l2 = l2->next;
      }
      else{
        cur->next = l1;
        cur = l1;
        l1 = l1->next;
      }
    }
    cur->next = (l1 ? l1 : l2);
    while(cur->next) cur = cur->next;
    return cur;
  }
};
