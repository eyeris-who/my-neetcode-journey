// https://neetcode.io/problems/remove-node-from-end-of-linked-list/question?list=neetcode150

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
  // remove (N-n)th node from the front
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* start = head;
    int count = 1;
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (count < n) {
      count++;
      head = head->next;
    }

    while(head->next) {
      head = head->next;
      prev = curr;
      curr = curr->next;
    }

    if (!prev) return curr->next;
    prev->next = curr->next;
    return start;
  }
};
