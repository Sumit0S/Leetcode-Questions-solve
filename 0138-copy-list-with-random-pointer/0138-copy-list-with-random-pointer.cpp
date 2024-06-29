/*
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mpp;
        Node* temp=head;
        while(temp!=NULL){
            Node* new_node=new Node(temp->val);
            mpp[temp]=new_node;
            temp=temp->next;
        }
        
        temp=head;

        while(temp!=NULL){
            Node* copynode=mpp[temp];
            copynode->next=mpp[temp->next];
            copynode->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }
};