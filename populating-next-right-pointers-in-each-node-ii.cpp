/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
            return;
        
        TreeLinkNode *tmpstart=new TreeLinkNode(0);
        TreeLinkNode *curr=NULL;
        
        TreeLinkNode *root1=root;
        root->next=NULL;
        
        while(root1!=NULL)
        {
            curr = tmpstart;
            
            while(root1!=NULL)
            {
                if(root1->left!=NULL)
                {
                    curr->next=root1->left;
                    curr=curr->next;
                }
                
                if(root1->right!=NULL)
                {
                    curr->next=root1->right;
                    curr=curr->next;
                }
                
                root1=root1->next;
            }
            
            curr->next=NULL;
            root1=tmpstart->next;
        }
        
        delete tmpstart;
    }
};
