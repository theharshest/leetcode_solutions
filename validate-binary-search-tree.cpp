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
    bool isValidBSTutil(TreeNode *root, long low, long high)
    {
        if(root==NULL)
            return true;
        
        long val=root->val;
        
        if(val>low && val<high)
            return isValidBSTutil(root->left, low, val) && isValidBSTutil(root->right, val, high);
        else
            return false;
    }

    bool isValidBST(TreeNode *root) {
        return isValidBSTutil(root, LONG_MIN, LONG_MAX);
    }
};
