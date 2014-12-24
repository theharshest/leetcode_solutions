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
    TreeNode *buildTreeutil(vector<int> &preorder, vector<int> &inorder, int low, int high, int &curr)
    {
        if(low>high)
            return NULL;
        
        int rootval=preorder[curr++];
        int ind=low;
        for(; ind<=high; ind++)
            if(inorder[ind]==rootval)
                break;
        
        TreeNode *tmp=new TreeNode(rootval);
        tmp->left=buildTreeutil(preorder, inorder, low, ind-1, curr);
        tmp->right=buildTreeutil(preorder, inorder, ind+1, high, curr);
        return tmp;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n=preorder.size();
        int curr=0;
        if(n==0)
            return NULL;
        return buildTreeutil(preorder, inorder, 0, n-1, curr);
    }
};
