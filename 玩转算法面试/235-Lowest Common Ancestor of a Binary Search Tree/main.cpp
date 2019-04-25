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
    p、q都小于root值，说明p、q都位于左侧，在其左子树上，递归左子树寻找
    p、q都大于root值，说明p、q都位于右侧，在有子树上寻找
    p<root值，q>root值，LCA为root
    p是q的root，q大于或小于p，LCA都是p，即root
    同理q是p的root，p大于或小于去，LCA都是q，即root
    所以最后三种情况可以合并为一种
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(p->val<root->val&&q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        if(p->val>root->val&&q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};
