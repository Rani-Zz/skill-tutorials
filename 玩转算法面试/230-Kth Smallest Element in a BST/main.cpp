/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode* root,TreeNode* &res,int k,int &count)
    {
        if(root==NULL) return;
        inorder(root->left,res,k,count);
        if(count==k) return;
        res = root;
        count++;
        if(count==k) return;
        inorder(root->right,res,k,count);
        
    }
public:
    /**
    *ÖÐÐò±éÀú ×ó¸ù ÓÒ
    */
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode* res = NULL;
        inorder(root,res,k,count);
        return res->val;
    }
};
