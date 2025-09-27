#include <iostream>
#include <vector>
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while(first != NULL && sec != NULL){
            ListNode* third = sec->next;

            sec->next = first;
            first->next = third;

            if(prev != NULL){
                prev->next = sec;
            } else {
                head = sec;
            }

            prev = first;
            first = third;
            if(third != NULL){
                sec = third->next;
            } else {
                sec = NULL;
            }
        }
        return head;
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {1, 2, 3, 4};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* swapped = sol.swapPairs(head);

    cout << "Swapped list: ";
    printList(swapped);

    return 0;
}
