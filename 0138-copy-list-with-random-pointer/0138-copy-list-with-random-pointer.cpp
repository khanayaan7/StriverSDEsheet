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
         if(head==NULL)return NULL;
        Node *temp=head;

        while(temp){
            Node *curr=new Node(temp->val);
            curr->next=temp->next;
            temp->next=curr;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            Node *rand=NULL;
            if(temp->random)rand=temp->random->next;
            temp=temp->next;
            temp->random=rand;
            temp=temp->next;
        }
        temp=head;
        Node *ans=head->next;
        while(temp){
            Node *curr=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            if(temp)curr->next=temp->next;
            
        }
        return ans;
    }
};