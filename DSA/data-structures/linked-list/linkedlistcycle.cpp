#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

int main() {
    // Creating a linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Creates a cycle

    Solution sol;
    if(sol.hasCycle(node1))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;

    // To prevent memory leak in real applications, you'd delete the nodes
    // But in this case, there's a cycle, so deletion must be handled carefully.

    return 0;
}
