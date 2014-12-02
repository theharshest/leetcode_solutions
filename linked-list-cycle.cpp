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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> flag;
        
        while(head!=NULL)
        {
            if(flag[head]==true)
                return true;
            flag[head]=true;
            head=head->next;
        }
        
        return false;
    }
};
