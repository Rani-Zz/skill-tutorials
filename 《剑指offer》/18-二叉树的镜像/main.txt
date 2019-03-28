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
    *ºóÐò±éÀú
    */
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL)
            return;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
    }
};