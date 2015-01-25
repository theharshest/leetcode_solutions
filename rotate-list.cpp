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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *first=head;
        ListNode *second=head;
        ListNode *tmphead=head;
        int len=0;
        
        while(first!=NULL)
        {
            first=first->next;
            len++;
        }
        
        first=head;
        
        k%=len;
        
        if(k==0)
            return head;
        
        while(k--)
            second=second->next;
            
        while(second->next!=NULL)
        {
            first=first->next;
            second=second->next;
        }
        
        ListNode *tmpfirst=first->next;
        first->next=NULL;
        
        head=tmpfirst;
        second->next=tmphead;
        
        return head;
    }
};
