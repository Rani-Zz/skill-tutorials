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
    int getDepth(TreeNode* root)
    {
        if(root==NULL) return 0;
        int ld = getDepth(root->left);
        if(ld==-1) return -1;
        int rd = getDepth(root->right);
        if(rd==-1) return -1;
        if(abs(ld-rd)>1) return -1;
        else
            return max(ld,rd)+1;
        
    }
public:
    /**
    *统计高度，不平衡返回-1
    *后序遍历
    */
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int res = getDepth(root);
        return res!=-1;
    }
};
