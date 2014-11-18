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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL)
            return NULL;
        else if(head->next==NULL)
            return head;
        else
        {
            ListNode *first, *second;
            first = head;
            second = head->next;
            
            while(1)
            {
                if(first->val==second->val)
                {
                    first->next = second->next;
                    if(first->next==NULL)
                        return head;
                    second=first->next;
                }
                else
                {
                    if(second->next==NULL)
                        return head;
                    first = first->next;
                    second = second->next;
                }
            }
        }
    }
};
