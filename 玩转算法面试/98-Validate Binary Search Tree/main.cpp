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
    *������� ���Ƿ��Ǵ�С����
    *�� �� ��
    */
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        
        TreeNode* pre = NULL;
        return isBST(root,pre);
    }
};
