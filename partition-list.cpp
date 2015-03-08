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
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL)
            return NULL;
        
        ListNode *lessones=new ListNode(-1);
        ListNode *greaterones=new ListNode(-1);
        ListNode *start1=lessones;
        ListNode *start2=greaterones;
        
        while(head!=NULL)
        {
            if(head->val < x)
            {
                lessones->next=head;
                lessones=lessones->next;
            }
            else
            {
                greaterones->next=head;
                greaterones=greaterones->next;
            }
            
            ListNode *tmp=head;
            head=head->next;
            tmp->next=NULL;
        }
        
        if(start1->next==NULL)
            return start2->next;
        else
        {
            lessones->next=start2->next;
            return start1->next;
        }
    }
};
