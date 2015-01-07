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
    TreeNode *buildTreeutil(vector<int> &in, vector<int> &post, int s, int e)
    {
        if(s>e)
            return NULL;
        
        int n=post.size();
        
        if(s==e)
        {
            int val=post[n-1];
            post.erase(post.end()-1);
            TreeNode *root=new TreeNode(val);
            return root;
        }
        
        int val=post[n-1];
        int ind=find(in.begin(), in.end(), val)-in.begin();
        TreeNode *root=new TreeNode(val);
        post.erase(post.end()-1);
        root->right=buildTreeutil(in, post, ind+1, e);
        root->left=buildTreeutil(in, post, s, ind-1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n=inorder.size();
        if(n==0)
            return NULL;
        return buildTreeutil(inorder, postorder, 0, n-1);
    }
};
