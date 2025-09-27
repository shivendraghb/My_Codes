#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data =val;
        next=NULL;
    }
};

class circularlist {
    Node* head;
    Node* tail;

public:
    circularlist(){
        head=tail=NULL;
    }

    void insertathead(int val){
        Node* newnode=new Node(val);
        if(tail==NULL){
            head=tail=newnode;
            tail->next=newnode;//or can write head
        } else{
            newnode->next=head;
            head=newnode;
            tail->next=head;
        }
    }

    void insertattail(int val){
        Node* newnode=new Node(val);
        if(tail==NULL){
            head=tail=newnode;
            tail->next=head;//or can write head
        } else{
            newnode->next=head;
            tail->next=newnode;
            tail=newnode;
        }
    }

    void deleteathead(){
        if(head==NULL) return;
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }else {
            Node* temp=head;
            head=head->next;
            tail->next=head;

            temp->next=NULL;
            delete temp;
        }
    }

    void deleteattail(){
        if(head==NULL) return;
        else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            Node* temp=tail;

            Node* prev=head;
            while(prev->next != tail){
                prev=prev->next;
            }

            tail=prev;
            tail->next=head;

            temp->next=NULL;
            delete temp;
        }
    }

    void print(){
        if(head==NULL) return;

        cout<<head->data<<"->";
        Node* temp=head->next;

        while(temp!=head){
            cout<<temp->data<<"->";
            temp=temp->next;
    }

    cout<<head->data<<endl;
    }
};

int main(){
    circularlist cll;

    cll.insertattail(1);
    cll.insertattail(2);
    cll.insertattail(3);

    cll.print();

    //cll.deleteathead();
    cll.deleteattail();
    cll.print();

    cll.deleteattail();
    cll.print();

    cll.deleteattail();
    cll.print();

    return 0;
}
