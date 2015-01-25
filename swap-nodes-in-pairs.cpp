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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return head;
            
        ListNode *first=head;
        ListNode *second=head->next;
        ListNode *third, *tmp;
        
        first->next=NULL;
        third=second->next;
        second->next=first;
        head=second;
        
        while(third!=NULL && third->next!=NULL)
        {
            tmp=third->next->next;
            second=third->next;
            first->next=second;
            second->next=third;
            third->next=NULL;
            first=third;
            third=tmp;
        }
        
        if(third!=NULL)
            first->next=third;
            
        return head;
    }
};
