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
    void pathSumutil(TreeNode *root, int sum, vector<vector<int> >& res, vector<int> curr)
    {
        if(root==NULL)
            return;
        else if(root->left==NULL && root->right==NULL)
        {
            int currsum=0;
            curr.push_back(root->val);
            for(int i=0; i<int(curr.size()); i++)
                currsum+=curr[i];
            if(currsum==sum)
                res.push_back(curr);
        }
        else
        {
            vector<int> tmp(curr);
            tmp.push_back(root->val);
            
            if(root->left!=NULL)
                pathSumutil(root->left, sum, res, tmp);
            
            if(root->right!=NULL)
                pathSumutil(root->right, sum, res, tmp);
        }
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> curr;
        pathSumutil(root, sum, res, curr);
        
        return res;
    }
};
