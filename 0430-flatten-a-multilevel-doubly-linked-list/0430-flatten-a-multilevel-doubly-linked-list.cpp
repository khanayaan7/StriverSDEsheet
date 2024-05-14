/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
    Node * solve(Node *head){
        if(!head)return NULL;
        if(head->child){
            Node *last=solve(head->child);
            Node *temp=head->next;
            head->next=head->child;
            head->next->prev=head;
            head->child=NULL;
            if(last)last->next=temp;
            if(temp)temp->prev=last;
            if(temp)return solve(temp);
        }
        if(head->next)
        return solve(head->next);
        else return head;
    }
};