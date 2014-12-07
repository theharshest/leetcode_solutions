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
    bool check_palindrome(vector<string>& p)
    {
        for(int i=0, j=int(p.size())-1; i<j; i++, j--)
            if(p[i]!=p[j])
                return false;
                
        return true;
    }

    bool isSymmetric(TreeNode *root) {
        if(root==NULL)
            return true;
        else
        {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                vector<string> val_tmp;
                vector<TreeNode*> tmp;
                
                while(!q.empty())
                {
                    tmp.push_back(q.front());
                    q.pop();
                }
                
                for(int i=0; i<int(tmp.size()); i++)
                {
                    if(tmp[i]->left != NULL)
                    {
                        q.push(tmp[i]->left);
                        val_tmp.push_back(to_string(tmp[i]->left->val));
                    }
                    else
                        val_tmp.push_back("x");

                    if(tmp[i]->right != NULL)
                    {
                        q.push(tmp[i]->right);
                        val_tmp.push_back(to_string(tmp[i]->right->val));
                    }
                    else
                        val_tmp.push_back("x");
                }
                
                if(!check_palindrome(val_tmp))
                    return false;
            }
        }
        
        return true;
    }
};
