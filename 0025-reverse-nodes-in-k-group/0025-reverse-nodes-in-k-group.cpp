/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head,*prev=NULL;
        auto rev=[&](ListNode *node) -> ListNode * {
            ListNode *prev=NULL,*nnext=NULL,*curr=node;
            while(curr){
                nnext=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nnext;
            }
            return prev;
        };
        while(temp){
            int t=k-1;
            ListNode *kth=temp;
            while(kth && t--)kth=kth->next;
            if(!kth){
                if(prev)prev->next=temp;
                return head;
            }
            ListNode *nnext=kth->next;
            kth->next=NULL;
            ListNode *reversed=rev(temp);
            if(temp==head){
                head=kth;
            }
            else{
                prev->next=kth;
            }
            prev=temp;
            temp=nnext;
        }
        return head;
    }
};