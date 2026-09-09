// https://neetcode.io/problems/linked-list-cycle-detection/question?list=neetcode150

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
  // naive solution with hashset - O(n) runtime, O(n) space
  bool hasCycle1(ListNode* head) {
    unordered_set<ListNode*> visited;
    while(head) {
      if (visited.contains(head)) return true;
      visited.insert(head);
      head = head->next;
    }
    return false;
  }

  // tortoise and hare algorithm (2p)
  // one pointer moves one step at a time while the other moves 2 steps at a time
  // When there is no cycle in the list, the loop ends when the fast pointer becomes null.
  // If a cycle exists, the fast pointer moves faster and continuously loops through the cycle.
  // With each step, it reduces the gap between itself and the slow pointer by one node.
  bool hasCycle2(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;

      if (fast == slow) return true;
    }
    return false;
  }
};
