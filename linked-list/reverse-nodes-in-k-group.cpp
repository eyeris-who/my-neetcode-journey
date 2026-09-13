// https://neetcode.io/problems/reverse-nodes-in-k-group/question

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (!check) return head;
            check = check->next;
        }

        ListNode dummy;
        dummy.next = head;
        ListNode* prevGroup = &dummy;
        
        while(true) {
            for (int i = 0; i < k; i++) {
                if (!head) return dummy.next;
                head = head->next;
            }
            ListNode* nextGroup = head; // already points to next

            // reverse group
            ListNode* prev = nextGroup;
            ListNode* curr = prevGroup->next;
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // prevGroup is now end of reversed list
            ListNode* endOfList = prevGroup->next;
            prevGroup->next = prev;
            prevGroup = endOfList;
        }
    }
};
