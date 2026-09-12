// https://neetcode.io/problems/merge-k-sorted-linked-lists/question

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
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* l3 = result;
        while (l1 || l2) {
            if (!l1) {
                if (!result) return l2;
                l3->next = l2;
                return result;
            }
            if (!l2) {
                if (!result) return l1;
                l3->next = l1;
                return result;
            }
            int val1 = l1->val;
            int val2 = l2->val;
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;
            
            if (val1 <= val2) {
                if (!result) {
                    result = l1;
                    l3 = l1;
                } else {
                    l3->next = l1;
                    l3 = l3->next;
                }
                l1 = next1;
            } else {
                if (!result) {
                    result = l2;
                    l3 = l2;
                } else {
                    l3->next = l2;
                    l3 = l3->next;
                }
                l2 = next2;
            }
            
            
        }
        return result;
    }
    ListNode* mergeLists(vector<ListNode*>& lists, int len) {
        if (lists.size() == 0) return nullptr;
        if (len == 1) return lists[0];
        for (int i = 0; i < len/2; i++) {
            lists[i] = merge2Lists(lists[i], lists[len-i-1]);
        }
        lists[0] = mergeLists(lists, len/2);
        if (len % 2 == 1) lists[0] = merge2Lists(lists[0], lists[len/2]);
        return lists[0];
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(lists, lists.size());
    }
};
