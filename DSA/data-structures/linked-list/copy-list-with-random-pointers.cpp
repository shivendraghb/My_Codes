#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if(head==NULL) return NULL;
            unordered_map<Node* , Node*> m;
            Node* newHead=new Node(head->val);
            Node* oldTemp=head->next;
            Node* newTemp=newHead;
            m[head]=newHead;
            while(oldTemp!=NULL){
                Node* copyNode=new Node(oldTemp->val);
                m[oldTemp]=copyNode;
                newTemp->next=copyNode;

                oldTemp=oldTemp->next;
                newTemp=newTemp->next;

            }
            oldTemp=head; newTemp=newHead;
            while(oldTemp!=NULL){
                newTemp->random=m[oldTemp->random];
                oldTemp=oldTemp->next;
                newTemp=newTemp->next;
            }
            return newHead;
        }
    };

    void printList(Node* head) {
        unordered_map<Node*, int> nodeToIndex;
        Node* temp = head;
        int index = 0;
        while (temp) {
            nodeToIndex[temp] = index++;
            temp = temp->next;
        }

        temp = head;
        while (temp) {
            cout << "[" << temp->val << ",";
            if (temp->random)
                cout << nodeToIndex[temp->random];
            else
                cout << "null";
            cout << "] ";
            temp = temp->next;
        }
        cout << endl;
    }

    int main() {
        // Input: [[7,null],[13,0],[11,4],[10,2],[1,0]]
        vector<pair<int, int>> input = {
            {7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}
        };

        // Step 1: Create all nodes
        vector<Node*> nodes;
        for (auto& p : input) {
            nodes.push_back(new Node(p.first));
        }

        // Step 2: Link next pointers
        for (int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->next = nodes[i + 1];
        }

        // Step 3: Link random pointers
        for (int i = 0; i < input.size(); ++i) {
            if (input[i].second != -1) {
                nodes[i]->random = nodes[input[i].second];
            }
        }

        // Step 4: Copy the list
        Solution sol;
        Node* copiedHead = sol.copyRandomList(nodes[0]);

        // Step 5: Print the copied list
        cout << "Copied List: ";
        printList(copiedHead);

        return 0;
    }
