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
    bool isBST(TreeNode* root,TreeNode* &pre)
    {
        if(root==NULL) return true;
        bool left = isBST(root->left,pre);
        if(!left) return false;
        if(pre!=NULL&&pre->val>=root->val) return false;
        pre = root;
        return isBST(root->right,pre);
    }
public:
    /**
    *中序遍历 看是否是从小到大
    *左 根 右
    */
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        
        TreeNode* pre = NULL;
        return isBST(root,pre);
    }
};
