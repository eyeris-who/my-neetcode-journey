// https://neetcode.io/problems/reorder-linked-list/question?list=neetcode150

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
  // brute force solution - O(n) time, O(n) space
  void reorderList1(ListNode* head) {
    vector<ListNode*> list;
    while(head) {
      list.push_back(head);
      head = head->next;
    }
    int len = (int)list.size();
    for (int i = 0; i < len/2; i++) {
      list[i]->next = list[len-i-1];
      list[len-i-1]->next = list[i+1];
    }
    list[len/2]->next = nullptr;
  }

  // FAST AND SLOW POINTERS TO FIND MIDPOINT
  void reorderList2(ListNode* head) {
    // divide list into 2 halves
    ListNode* slow = head;
    ListNode* fast = head->next;
    ListNode* l1 = head;
    ListNode* l2 = head;
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      l2 = slow;
    }

    // split two lists
    l2 = slow->next;
    slow->next = nullptr;

    // reverse second half
    ListNode* curr = l2; // start of unread old list
    ListNode* prev = nullptr; // start of reversed list
    while(curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    l2 = prev; // start of list

    // put second half in first half
    while (l2) {
      ListNode* next1 = l1->next;
      ListNode* next2 = l2->next;
      l1->next = l2;
      l2->next = next1;
      l1 = next1;
      l2 = next2;
    }
  }
};
