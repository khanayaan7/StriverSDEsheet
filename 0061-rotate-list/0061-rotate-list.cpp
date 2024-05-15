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
    ListNode* rotateRight(ListNode* head, int k) {
    if(!head)return NULL;
      int len=0;
      ListNode *temp=head,*last=head;
      while(temp){
        len++;
        last=temp;
        temp=temp->next;
      }
      k%=len;  
      if(k==0)return head;
      int move=len-k-1;
      temp=head;
      while(move--){
        temp=temp->next;
      }
      last->next=head;
      head=temp->next;
      temp->next=NULL;
        return head;
    }
};