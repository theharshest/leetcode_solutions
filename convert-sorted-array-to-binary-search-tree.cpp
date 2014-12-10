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
    TreeNode *sortedArrayToBSTutil(vector<int> &num, int low, int high)
    {
        if(low>high)
            return NULL;

        int mid=(low + high)/2;
        TreeNode *root=new TreeNode(num[mid]);
        root->left=sortedArrayToBSTutil(num, low, mid-1);
        root->right=sortedArrayToBSTutil(num, mid+1, high);
        
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n=num.size();
        if(n==0)
            return NULL;
        
        return sortedArrayToBSTutil(num, 0, n-1);
    }
};
