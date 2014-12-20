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
    void sumNumbersutil(TreeNode *root, vector<int>& nums, int num)
    {
        if(root==NULL && num==0)
            return;
        else
        {
            if(root->left==NULL && root->right==NULL)
                nums.push_back(num*10+root->val);
            else if(root->left==NULL)
                sumNumbersutil(root->right, nums, num*10+root->val);
            else if(root->right==NULL)
                sumNumbersutil(root->left, nums, num*10+root->val);
            else
            {
                sumNumbersutil(root->right, nums, num*10+root->val);
                sumNumbersutil(root->left, nums, num*10+root->val);
            }
        }
    }

    int sumNumbers(TreeNode *root) {
        vector<int> nums;
        sumNumbersutil(root, nums, 0);
        
        int res=0;
        
        for(int i=0; i<int(nums.size()); i++)
            res+=nums[i];
            
        return res;
    }
};
