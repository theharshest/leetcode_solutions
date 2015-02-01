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
    ListNode *mergetwoLists(ListNode *first, ListNode *second)
    {
        if(first==NULL)
            return second;
            
        if(second==NULL)
            return first;
            
        ListNode *start;
        ListNode *tmp=new ListNode(0);
        ListNode *head=tmp;
        
        while(first!=NULL && second!=NULL)
        {
            if(first->val < second->val)
            {
                tmp->next=first;
                first=first->next;
            }
            else
            {
                tmp->next=second;
                second=second->next;
            }
            tmp=tmp->next;
        }
            
        if(first!=NULL)
            tmp->next=first;
        else if(second!=NULL)
            tmp->next=second;
            
        return head->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n=lists.size();
        
        if(n==0)
            return NULL;
        
        if(n==1)
            return lists[0];
        
        ListNode *tmp;
        
        while(int(lists.size())>1)
        {
            tmp=mergetwoLists(lists[0], lists[1]);
            lists.push_back(tmp);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        
        return tmp;
    }
};
