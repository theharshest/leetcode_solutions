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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > trav;
        if(root==NULL)
            return trav;
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                vector<TreeNode*> tmp;
                while(!q.empty())
                {
                    tmp.push_back(q.front());
                    q.pop();
                }
                vector<int> val_tmp;
                for(int i=0; i<int(tmp.size()); i++)
                {
                    val_tmp.push_back(tmp[i]->val);
                    if(tmp[i]->left!=NULL)
                        q.push(tmp[i]->left);
                    if(tmp[i]->right!=NULL)
                        q.push(tmp[i]->right);
                }   
                trav.push_back(val_tmp);
            }
        }
        
        return trav;
    }
};
