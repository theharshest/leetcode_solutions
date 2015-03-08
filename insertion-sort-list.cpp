/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/* http://cslibrary.stanford.edu/105/LinkedListProblems.pdf */
 
class Solution {
public:
    void sortinsert(ListNode **headref, ListNode **newnoderef)
    {
        ListNode *newnode=*newnoderef;
        ListNode *head=*headref;
        if(head==NULL)
            *headref=newnode;
        else if(newnode->val < head->val)
        {
            newnode->next=head;
            *headref=newnode;
        }
        else
        {
            ListNode *headnext=head->next;
            
            while(headnext!=NULL && headnext->val < newnode->val)
            {
                headnext=headnext->next;
                head=head->next;
            }
            
            newnode->next=head->next;
            head->next=newnode;
        }
    }

    ListNode *insertionSortList(ListNode *head) {
        ListNode *result=NULL;
        
        if(head==NULL)
            return NULL;
        
        while(head!=NULL)
        {
            ListNode *headnext=head->next;
            head->next=NULL;
            sortinsert(&result, &head);
            head=headnext;
        }
        
        return result;
    }
};
