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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int n1=0, n2=0;
        ListNode *t1=l1, *t2=l2;
        
        while(t1)
        {
            n1++;
            t1=t1->next;
        }
        while(t2)
        {
            n2++;
            t2=t2->next;
        }
        
        ListNode *larger=l1;
        ListNode *smaller=l2;
        ListNode *prev, *res;
        
        if(n2>n1)
        {
            larger=l2;
            smaller=l1;
        }
        
        res=larger;
        
        int carry=0;
        
        while(smaller!=NULL)
        {
            int sum=smaller->val + larger->val + carry;
            if(sum>9)
            {
                sum%=10;
                carry=1;
            }
            else
                carry=0;
                
            larger->val=sum;
            smaller=smaller->next;
            prev=larger;
            larger=larger->next;
        }
        
        if(larger==NULL)
        {
            if(carry)
            {
                ListNode *tmp=new ListNode(1);
                prev->next=tmp;
            }
        }
        else
        {
            while(larger && carry)
            {
                int sum=larger->val + carry;
                
                if(sum>9)
                {
                    sum%=10;
                    carry=1;
                }
                else
                    carry=0;
                
                larger->val=sum;
                prev=larger;
                larger=larger->next;
            }
            
            if(carry)
            {
                ListNode *tmp=new ListNode(1);
                prev->next=tmp;
            }
        }
        
        return res;
    }
};
