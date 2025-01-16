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
        if(head==NULL) return NULL;
        Node* temp=head;
        while(temp!=NULL){
            Node* n=new Node(temp->val);
            Node* next=temp->next;
            temp->next=n;
            n->next=next;
            temp=next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random==NULL) temp->next->random=NULL;
            else temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        Node* p=head->next;
        Node* z=head;
        while(z!=NULL){
            Node* next=z->next->next;
            if(next==NULL) z->next->next=NULL;
            else z->next->next=next->next;
            z->next=next;
            z=next;
        }
        return p;
    }
};