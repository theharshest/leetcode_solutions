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
    void inorderTraversalutil(TreeNode *root, vector<int>& inorder)
    {
        if(root==NULL)
            return;
        else
        {
            inorderTraversalutil(root->left, inorder);
            inorder.push_back(root->val);
            inorderTraversalutil(root->right, inorder);
        }
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorder;
        inorderTraversalutil(root, inorder);
        
        return inorder;
    }
};
