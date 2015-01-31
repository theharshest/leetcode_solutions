/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> stk;
 
    void populateStack(TreeNode *root)
    {
        while(root!=NULL)
        {
            stk.push(root);
            root=root->left;
        }
    }
 
    BSTIterator(TreeNode *root) {
        populateStack(root);
    }
 
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
 
    /** @return the next smallest number */
    int next() {
        TreeNode *tmp=stk.top();
        stk.pop();
        populateStack(tmp->right);
        return tmp->val;
    }
};
 
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
