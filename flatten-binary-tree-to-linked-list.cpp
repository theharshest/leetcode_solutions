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
    void flattenutil(TreeNode *root, TreeNode *& prev)
    {
        if(!root)
            return;
        
        if(prev)
        {
            prev->right=root;
            prev->left=NULL;
        }
        
        prev=root;
        
        TreeNode *right=root->right;
        
        flattenutil(root->left, prev);
        flattenutil(right, prev);
    }

    void flatten(TreeNode *root) {
        TreeNode *prev=NULL;
        flattenutil(root, prev);
    }
};
