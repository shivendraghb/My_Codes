#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
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
        ListNode* reverseList(ListNode* head) {
            ListNode* prev=NULL;
            ListNode* curr=head;
            ListNode* next=NULL;

            while(curr!=NULL){
                next=curr->next;
                curr->next=prev;

                prev=curr;
                curr=next;
            }
            return prev;
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
    // Creating linked list 1->2->3->4->5
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4,node5);
    ListNode* node3 = new ListNode(3,node4);
    ListNode* node2 = new ListNode(2,node3);
    ListNode* head = new ListNode(1,node2);

    cout<<"original list: ";
    printLL(head);

    Solution solution;
    ListNode* reversedHead=solution.reverseList(head);

    cout<<"reversed list: ";
    printLL(reversedHead);

    return 0;

}
