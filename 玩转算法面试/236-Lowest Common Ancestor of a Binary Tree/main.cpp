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
    左 右找到p q返回根
    左找到 返回左
    右找到 返回右
    都没找到 返回NULL
    
    递归找到左右都找到的结点即为LCA
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left&&right) return root;
        else if(left) return left;
        else if(right) return right;
        else return NULL;
    }
};
