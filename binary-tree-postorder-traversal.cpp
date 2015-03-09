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
    void initializestack(TreeNode *root, stack<TreeNode*>& stk)
    {
        while(root!=NULL)
        {
            stk.push(root);
            if(root->left == NULL)
                root=root->right;
            else
                root=root->left;
        }
    }

    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> stk;
        initializestack(root, stk);
        
        vector<int> postorder;
        
        while(!stk.empty())
        {
            TreeNode *curr=stk.top();
            stk.pop();
            
            postorder.push_back(curr->val);
            
            if(stk.empty())
                break;
            
            TreeNode *next=stk.top();
            
            if(next!=NULL && next->left==curr)
                initializestack(next->right, stk);
        }
        
        return postorder;
    }
};
