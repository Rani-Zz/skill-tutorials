/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
private:
    void convertTree(TreeNode* root, TreeNode* &pre)
    {
        if(!root)
            return;
        convertTree(root->left,pre);
        root->left = pre;
        if(pre)
        {
            pre->right = root;
        }
        pre = root;
        convertTree(root->right,pre);
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree)
            return NULL;
        TreeNode* pre = NULL;
        convertTree(pRootOfTree,pre);
        while(pre->left!=NULL)
        {
            pre = pre->left;
        }
        return pre;
    }
};