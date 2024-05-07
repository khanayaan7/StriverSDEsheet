/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
        ListNode *l1=h1,*l2=h2;
        while(l1!=l2){
            if(l1)l1=l1->next;
            else l1=h2;
            if(l2)l2=l2->next;
            else l2=h1;
        }
        return l1;
    }
};