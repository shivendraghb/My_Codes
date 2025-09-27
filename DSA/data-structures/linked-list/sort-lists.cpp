#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if(!head || !head->next) return head;
            int length=0;
            ListNode* node=head;
            while(node){
                length++;
                node=node->next;
            }
            for(int size=1;size<length;size *= 2){
                ListNode* curr=head;
                ListNode* prev=nullptr;
                head=nullptr;
                while(curr){
                    ListNode* left=curr;
                    ListNode* right=split(left,size);
                    curr=split(right,size);

                    auto[mergedHead,mergedTail]=merge(left,right);
                    if(!head) head=mergedHead;
                    if(prev) prev->next=mergedHead;
                    prev=mergedTail;
                }
            }
            return head;
        }

    private:
        ListNode* split(ListNode* head,int size){
            while(--size && head) head=head->next;
            if(!head) return nullptr;
            ListNode* second=head->next;
            head->next=nullptr;
            return second;
        }

        pair<ListNode*,ListNode*> merge(ListNode* l1,ListNode* l2){
            ListNode* head=nullptr;
            ListNode* tail=nullptr;

            while(l1 && l2){
                ListNode* node=nullptr;
                if(l1->val < l2->val){
                    node=l1;
                    l1=l1->next;
                } else{
                    node=l2;
                    l2=l2->next;
                }
                if(!head) head=tail=node;
                else{
                    tail->next=node;
                    tail=node;
                }
            }
            ListNode* remaining=l1?l1:l2;
            while(remaining){
                if(!head) head=tail=remaining;
                else{
                    tail->next=remaining;
                    tail=remaining;
                }
                remaining=remaining->next;
            }
            tail->next=nullptr;
            return {head,tail};
        }
    };
//to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}


int main() {
    vector<int> values = {4, 2, 1, 3, 5};
    ListNode* list = createList(values);

    cout << "Original List: ";
    printList(list);

    Solution sol;
    ListNode* sortedList = sol.sortList(list);

    cout << "Sorted List: ";
    printList(sortedList);

    return 0;
}

