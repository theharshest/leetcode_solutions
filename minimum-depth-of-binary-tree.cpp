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
        if(node->left == NULL && node->right == NULL)
            return true;
        return false;
    }
    
    int minDepth(TreeNode *root) {
        if(root==NULL)
            return 0;
        else if(isleaf(root))
            return 1;
        else if(root->right == NULL)
            return minDepth(root->left) + 1;
        else if(root->left == NULL)
            return minDepth(root->right) + 1;
        else
            return min(minDepth(root->right), minDepth(root->left)) + 1;
    }
};
