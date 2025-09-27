#include<iostream>
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
        ListNode* middleNode(ListNode* head) {
            //slow fast pointer approach
            ListNode* slow=head;
            ListNode* fast=head;

            while(fast!=NULL && fast->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow;
        }
    };

    void printLL(ListNode* head){
        while(head!=NULL){
            cout<<head->val;
            if(head->next!=NULL)
                cout<<" -> ";
            head=head->next;
        }
        cout<<endl;
    }

int main(){

    // Creating linked list 1->2->3->4->5->6
    ListNode* node6 = new ListNode(6);
    ListNode* node5 = new ListNode(5,node6);
    ListNode* node4 = new ListNode(4,node5);
    ListNode* node3 = new ListNode(3,node4);
    ListNode* node2 = new ListNode(2,node3);
    ListNode* head = new ListNode(1,node2);

    cout<<"the list is: ";
    printLL(head);

    Solution solution;
    ListNode* result=solution.middleNode(head);

    cout<<"the middle of the linked list is: "<<"value= "<<result->val<<" , address= "<<result<<endl;

    return 0;

}
