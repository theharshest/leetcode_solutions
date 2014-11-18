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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *first, *second;
        ListNode *final = new ListNode(0);
        ListNode *third = new ListNode(0);
        
        if(l1==NULL && l2==NULL)
            return NULL;
        else if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        else
        {
            first = l1;
            second = l2;
            third = final;
            bool f = 0;
            
            while(1)
            {
                if(first->val < second->val)
                {
                    third->val = first->val;
                    first = first->next;
                }
                else
                {
                    third->val = second->val;
                    second = second->next;
                }
                
                if(first==NULL)
                    break;
                else if(second==NULL)
                {
                    f = 1;
                    break;
                }
                
                ListNode *tmp = new ListNode(0);
                third->next = tmp;
                third = tmp;
            }
            
            if(!f)
                third->next = second;
            else
                third->next = first;
            
            return final;
        }
    }
};
