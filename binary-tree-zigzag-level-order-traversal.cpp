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
    void zigzagLevelOrderutil(vector<vector<int> >& res, stack<TreeNode*> stk, bool ord)
    {
        if(stk.empty())
            return;
        
        stack<TreeNode*> newstack;
        vector<int> curr;
        while(!stk.empty())
        {
            TreeNode *tmp=stk.top();
            curr.push_back(tmp->val);
            if(ord)
            {
                if(tmp->left)
                    newstack.push(tmp->left);
                if(tmp->right)
                    newstack.push(tmp->right);
            }
            else
            {
                if(tmp->right)
                    newstack.push(tmp->right);
                if(tmp->left)
                    newstack.push(tmp->left);
            }
            stk.pop();
        }
        
        res.push_back(curr);
        ord=!ord;
        
        zigzagLevelOrderutil(res, newstack, ord);
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        
        if(root==NULL)
            return res;
        
        stack<TreeNode*> stk;
        stk.push(root);
        bool ord=true;
        zigzagLevelOrderutil(res, stk, ord);
        
        return res;
    }
};
