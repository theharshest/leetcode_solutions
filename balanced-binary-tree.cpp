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
    int height(TreeNode *root) {
        if(root==NULL)
            return 0;
        else
            return max(height(root->left), height(root->right)) + 1;
    }
    
    bool isleaf(TreeNode *root) {
        if(root->left==NULL && root->right==NULL)
            return true;
        return false;
    }

    bool isBalanced(TreeNode *root) {
        if(root==NULL)
            return true;
        else if(abs(height(root->left)-height(root->right)) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        else
            return false;
    }
};
