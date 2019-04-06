class Solution {
private:
    int getDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        int lf = getDepth(root->left);
        if(lf== -1) return -1;
        int lr = getDepth(root->right);
        if(lr==-1) return -1;
        return (abs(lf-lr))>1? -1: 1+max(lf,lr);
    }
public:
    /**
    *递归后序遍历
    *如果某个子树不平衡直接返回fals
    *相当于后序找每个结点的深度，如果左右子树相差超过1就不平衡
    */
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return getDepth(pRoot)!=-1;
    }
};