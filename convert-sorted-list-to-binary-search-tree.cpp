/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val; 
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBSTutil(ListNode *head, ListNode *tail)
    {
        if(head==NULL)
            return NULL;
        
        if(head==tail)
        {
            TreeNode *root=new TreeNode(head->val);
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        
        if(head->next==tail)
        {
            TreeNode *root=new TreeNode(head->val);
            root->left=NULL;
            TreeNode *tmp=new TreeNode(head->next->val);
            root->right=tmp;
            return root;
        }
        
        int n=0;
        
        ListNode *tmp=head;
        while(tmp!=tail)
        {
            n++;
            tmp=tmp->next;
        }
        
        ListNode *mid=head->next;
        ListNode *tail1=head;
        n/=2;
        
        while(--n)
        {
            tail1=tail1->next;
            mid=mid->next;
        }

        TreeNode *root=new TreeNode(mid->val);
        root->left=sortedListToBSTutil(head, tail1);
        root->right=sortedListToBSTutil(mid->next, tail);
        
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        if(head==NULL)
            return NULL;
        
        ListNode *tail=head;
        while(tail->next!=NULL)
            tail=tail->next;
            
        return sortedListToBSTutil(head, tail);
    }
};
