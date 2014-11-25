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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode*> q;
        vector<vector<int> > res;
        
        if(root==NULL)
            return res;
        
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> tmp1;
            vector<TreeNode*> tmp2;
            while(!q.empty())
            {
                tmp1.push_back(q.front()->val);
                tmp2.push_back(q.front());
                q.pop();
            }
            res.push_back(tmp1);
            for(int i=0; i<int(tmp2.size()); i++)
            {
                if(tmp2[i]->left)
                    q.push(tmp2[i]->left);
                if(tmp2[i]->right)
                    q.push(tmp2[i]->right);
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
