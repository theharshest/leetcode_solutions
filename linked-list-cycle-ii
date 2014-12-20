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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        
        ListNode *ptr1=head;
        ListNode *ptr2=head->next;
        
        if(ptr2==NULL)
            return NULL;
        
        ptr2=ptr2->next;
            
        while(1)
        {
            ptr1=ptr1->next;

            if(ptr1==ptr2)
                break;
            
            if(ptr2==NULL || ptr2->next==NULL)
                return NULL;
            else
                ptr2=ptr2->next->next;
        }
        
        ptr2=head;

        while(1)
        {
            if(ptr1==ptr2)
                return ptr1;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
};
