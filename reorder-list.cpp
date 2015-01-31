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
    ListNode *reverse(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *tmp=head->next;
        ListNode *tmp1=tmp->next;
        
        head->next=NULL;
        
        while(tmp1!=NULL)
        {
            tmp->next=head;
            head=tmp;
            tmp=tmp1;
            tmp1=tmp1->next;
        }
        
        tmp->next=head;
        
        return tmp;
    }
 
    void reorderList(ListNode *head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return;
        
        ListNode *head1=head;
        ListNode *head2=head->next;
        
        while(head2!=NULL && head2->next!=NULL)
        {
            head1=head1->next;
            head2=head2->next->next;
        }
        
        head2=head1->next;
        
        head1->next=NULL;
        head1=head;
        
        head2=reverse(head2);
        
        ListNode *tmp1, *tmp2;
        
        while(head1!=NULL && head2!=NULL)
        {
            tmp1=head1->next;
            tmp2=head2->next;
            head1->next=head2;
            head2->next=tmp1;
            head1=tmp1;
            head2=tmp2;
        }
    }
};
