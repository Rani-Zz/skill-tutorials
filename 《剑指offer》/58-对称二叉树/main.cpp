/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
private:
    bool isMirror(TreeNode* root1,TreeNode* root2)
    {
        if(root1==NULL&&root2==NULL)
            return true;
        if(root1==NULL||root2==NULL)
            return false;
        if(root1->val!=root2->val)
            return false;
        return isMirror(root1->left,root2->right)&&isMirror(root1->right,root2->left);
    }
public:
    /**
    *根结点相同，左右子树对称
    */
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isMirror(pRoot,pRoot);
    }

};