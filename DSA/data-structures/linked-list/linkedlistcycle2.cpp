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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool isCycle=false;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                isCycle=true;
                break;
            }
        }

        if(!isCycle){
            return NULL;
        }
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

int main() {
    // Creating a cycle list: 3 -> 2 -> 0 -> -4 -> (points back to 2)
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creates the cycle

    Solution sol;
    ListNode* cycleNode = sol.detectCycle(head);

    if(cycleNode != NULL){
        cout << "Cycle starts at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Note: We won't delete nodes here because of the cycle (to avoid infinite loop)
    return 0;
}
