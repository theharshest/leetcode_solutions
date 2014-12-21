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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode *head1=head;
        ListNode *head2=head;
        
        while(n--)
            head2=head2->next;
        
        if(head2==NULL)
        {
            head=head->next;
            return head;
        }
        
        while(head2->next!=NULL)
        {
            head1=head1->next;
            head2=head2->next;
        }
        
        head1->next=head1->next->next;
        
        return head;
    }
};
