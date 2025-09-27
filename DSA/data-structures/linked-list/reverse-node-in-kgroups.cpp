#include<iostream>
#include<vector>
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
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* temp = head;
            int cnt = 0;
            while(cnt < k) {
                if(temp == NULL) return head;
                temp = temp->next;
                cnt++;
            }

            ListNode* prevNode = reverseKGroup(temp, k);

            temp = head; cnt = 0;
            while(cnt < k) {
                ListNode* next = temp->next;
                temp->next = prevNode;

                prevNode = temp;
                temp = next;

                cnt++;
            }

            return prevNode;
        }
    };

    void printList(ListNode* head) {
        while(head) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "NULL\n";
    }

    ListNode* createList(const vector<int>& vals) {
        if(vals.empty()) return nullptr;
        ListNode* head = new ListNode(vals[0]);
        ListNode* current = head;
        for(size_t i = 1; i < vals.size(); ++i) {
            current->next = new ListNode(vals[i]);
            current = current->next;
        }
        return head;
    }


int main() {
    vector<int> vals = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = createList(vals);
    cout << "Original list:\n";
    printList(head);

    Solution sol;
    ListNode* result = sol.reverseKGroup(head, k);

    cout << "List after reversing in groups of " << k << ":\n";
    printList(result);

    return 0;
}
