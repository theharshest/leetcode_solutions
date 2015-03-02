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
    int maxPathSumutil(TreeNode *root, int& currsum)
    {
        if(!root)
            return 0;
        else
        {
            int leftsum=maxPathSumutil(root->left, currsum);
            int rightsum=maxPathSumutil(root->right, currsum);
            
            if(leftsum<0)
                leftsum=0;
                
            if(rightsum<0)
                rightsum=0;
            
            if(leftsum+rightsum+root->val > currsum)
                currsum=leftsum+rightsum+root->val;
                
            return root->val + max(leftsum, rightsum);
        }
    }

    int maxPathSum(TreeNode *root) {
        int currsum=INT_MIN;
        maxPathSumutil(root, currsum);
        
        return currsum;
    }
};
