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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=0, lenB=0;
        ListNode* A=headA;
        ListNode* B=headB;
        
        while(A!=NULL)
        {
            lenA++;
            A=A->next;
        }
        
        while(B!=NULL)
        {
            lenB++;
            B=B->next;
        }
        
        if(lenA>=lenB)
        {
            for(int i=0; i<lenA-lenB; i++)
                headA=headA->next;
        }
        else
        {
            for(int i=0; i<lenB-lenA; i++)
                headB=headB->next;
        }
        
        while(headA!=NULL)
        {
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        
        return NULL;
    }
};
