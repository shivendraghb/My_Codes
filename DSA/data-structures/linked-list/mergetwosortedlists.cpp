#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
            if(head1==NULL || head2==NULL){
                return head1==NULL?head2:head1;
            }

            if(head1->val <= head2->val){
                head1->next = mergeTwoLists(head1->next,head2);
                return head1;
            }
            else{
                head2->next = mergeTwoLists(head1,head2->next);
                return head2;
            }
        }
    };


int main() {
    // Creating first linked list: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // Creating second linked list: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    // Printing the merged list
    cout << "Merged List: ";
    while(merged != nullptr) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;

    return 0;
}
