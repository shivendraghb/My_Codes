#include<iostream>
#include<algorithm>
using namespace std;
//linked list is a kind of linear DS where you can only traverse forward using the head pointer
class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            data=val;
            next=NULL;
        }
};
class List{
    Node* head;
    Node* tail;

public:
List(){
    head=tail=NULL;
}
    //PUSH FRONT
    void push_front(int val){ //O(1)
        Node* newnode=new Node(val);//persists in the memmory even after the function call ends
        //Node newnode(val); //static object
        if(head==NULL){
            head=tail=newnode;
            return;
        } else{
            newnode->next=head;  //here newnode is a pointer and here in memory (*newnode) is dereferenced
      //or (*newnode).next=head  //and its "next" property is assigned the value of "head";
            head=newnode;
        }
    }

    void push_back(int val){ //O(1)
        Node* newnode=new Node(val);

        if(head == NULL){
            head=tail=newnode;
            return;
        } else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    void pop_front(){ //O(1)
        if(head==NULL){
            cout<<"ll is empty\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;

        delete temp;
    }

    void pop_back(){ //O(n)
        if(head==NULL){
            cout<<"ll is empty\n";
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }

    void insert(int val,int pos){ //O(n)
        if(pos<0){
            cout<<"invalid pos\n";
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }

        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"invalid pos\n";
                return;
            }
            temp=temp->next;
        }
        Node* newnode=new Node(val);
        newnode->next=temp->next;
        temp->next=newnode;
    }

    int search(int key){ //O(n)
        Node* temp=head;
        int index=0;
        while(temp!=NULL && temp->data!=key){
            temp=temp->next;
            index++;
        }
        if(temp==NULL) return -1;
        return index;
    }

    void printLL(){ //O(n)
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<'\n';
    }
};
int main()
{
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    cout<<"after pushing\n";
    ll.printLL();

    cout<<"after inserting\n";
    ll.insert(4,0);
    ll.printLL();

    cout<<"searching\n";
    cout<<ll.search(5)<<endl;

    ll.printLL();

    return 0;
}
