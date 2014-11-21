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
    bool isleaf(TreeNode *node) {
        if(node->left==NULL && node->right==NULL)
            return true;
        return false;
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL)
            return false;
        else if(isleaf(root))
            if(root->val==sum)
                return true;
            else
                return false;
        else
            return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};
