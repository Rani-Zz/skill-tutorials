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
    int sumLeft(TreeNode* root,bool isleft)
    {
        if(root==NULL) return 0;
        if(isleft&&root->left==NULL&&root->right==NULL)
        {
            return root->val;
        }
        
        return sumLeft(root->left,true)+sumLeft(root->right,false);
    }
public:
    /**
    *求和的条件：左子树 且是根节点
    *遍历的时候可以标记是否是左子树
    *再用左右子树是否为空判断是否为根节点
    */
    int sumOfLeftLeaves(TreeNode* root) {
        return sumLeft(root,false);
    }
};
