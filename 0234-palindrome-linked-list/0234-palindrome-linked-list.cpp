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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *prev=NULL,*curr=slow,*nnext=NULL;
        while(curr){
            nnext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nnext;
        }
        slow=head;
        while(prev && slow){
            if(slow->val!=prev->val)return false;
            slow=slow->next;
            prev=prev->next;
        }
        return true;
    }
};