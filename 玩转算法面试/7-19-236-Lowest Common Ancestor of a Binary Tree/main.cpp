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
public:
    /**
    *其实就是找这两个结点
    *左右根 
    *左右找到返回结点 否则 root
    *左找到 返回左
    *右找到 返回右
    *递归寻找左右都找到的结点
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left&&right) return root;
        else if(left) return left;
        else if(right) return right;
        else return NULL;
    }
};
