// https://neetcode.io/problems/copy-linked-list-with-random-pointer/question

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* copy = new Node(head->val);
        Node* result = copy;
        Node* start = head;
        unordered_map<Node*, Node*> oldToNew;
        oldToNew.insert({head, copy});
        while(head->next) {
            copy->next = new Node(head->next->val);
            copy = copy->next;
            head = head->next;
            oldToNew.insert({head, copy});
        }

        copy = result;
        while(start) {
            copy->random = oldToNew[start->random];
            start = start->next;
            copy = copy->next;
        }

        return result;
    }
};
