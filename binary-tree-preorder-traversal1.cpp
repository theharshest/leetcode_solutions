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
    void preorderTraversal_util(TreeNode *root, vector<int>& preorder) {
        if(root==NULL)
            return;
        else
            preorder.push_back(root->val);
        preorderTraversal_util(root->left, preorder);
        preorderTraversal_util(root->right, preorder);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorder;
        preorderTraversal_util(root, preorder);
        
        return preorder;
    }
};
