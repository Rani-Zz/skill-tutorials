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
public:
    /**
    *µÝ¹éÇ°Ðò±éÀú
    */
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)
            return 0;
        int lf = TreeDepth(pRoot->left);
        int lr = TreeDepth(pRoot->right);
        return max(lf,lr)+1;
    }
};