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
    void inorderTraversalutil(TreeNode *root, stack<TreeNode*>& stk)
    {
        while(root!=NULL)
        {
            stk.push(root);
            root=root->left;
        }
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorder;
        stack<TreeNode*> stk;
        
        inorderTraversalutil(root, stk);
        
        while(!stk.empty())
        {
            TreeNode *curr=stk.top();
            inorder.push_back(curr->val);
            stk.pop();
            inorderTraversalutil(curr->right, stk);
        }
        
        return inorder;
    }
};
