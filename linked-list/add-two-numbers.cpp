// https://neetcode.io/problems/add-two-numbers/question

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* result = l3;
        bool firstIt = true;

        while(l1 || l2) {
            int val1 = 0;
            int val2 = 0;
            if (l1) val1 = l1->val;
            if (l2) val2 = l2->val;

            int val3 = val1+val2;
            cout << val3 << endl;
            if (val3 > 9) {
                val3 = val3 % 10;
                if (l1->next) l1->next->val += 1;
                else l1->next = new ListNode(1);
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            if (firstIt) {
                l3->val = val3;
                firstIt = false;
                continue;
            }
            l3->next = new ListNode(val3);
            l3 = l3->next;
            
        }

        return result;
    }

    // no modification of l1 or l2
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* result = l3;
        bool firstIt = true;
        bool carry = false;

        while(l1 || l2) {
            int val1 = 0;
            int val2 = 0;
            if (l1) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val2 = l2->val;
                l2 = l2->next;
            }

            int val3 = val1+val2;
            if (carry) val3 += 1;
            cout << val3 << endl;
            if (val3 > 9) {
                val3 = val3 % 10;
                carry = true;
            } else {
                carry = false;
            }

            if (firstIt) {
                l3->val = val3;
                firstIt = false;
                continue;
            }
            l3->next = new ListNode(val3);
            l3 = l3->next;
            
        }
        if (carry) l3->next = new ListNode(1);

        return result;
    }
};