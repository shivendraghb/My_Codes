/**
 * Definition for singly-linked list node.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        // Recursively sort the rest of the list
        ListNode* sorted = insertionSortList(head->next);
        
        // Insert current node into sorted list
        return insert(sorted, head);
    }
    
private:
    ListNode* insert(ListNode* sorted, ListNode* node) {
        // Base case: insert at beginning
        if (!sorted || sorted->val >= node->val) {
            node->next = sorted;
            return node;
        }
        
        // Recursively find correct position
        sorted->next = insert(sorted->next, node);
        return sorted;
    }
};

