/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if((root==NULL) || (root->left==NULL && root->right==NULL))
            return;
        
        TreeLinkNode *curr=root;
        
        while(root->left!=NULL)
        {
            while(curr->next!=NULL)
            {
                curr->left->next=curr->right;
                curr->right->next=curr->next->left;
                curr=curr->next;
            }
            curr->left->next=curr->right;
            root=root->left;
            curr=root;
        }
    }
};
