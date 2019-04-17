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
    bool isSubtree(TreeNode* root1,TreeNode* root2)
    {
        if(root2==NULL) return true;
        if(root1==NULL) return false;
        
        if(root1->val!=root2->val) return false;
        bool res = true;
        if(res) res = isSubtree(root1->left,root2->left);
        if(res) res = isSubtree(root1->right,root2->right);
        return res;
    }
public:
    /**
    *前序遍历，先找到子树的根节点，再判断子树是否相同
    *如果不同的话要继续找，不能直接返回false
    */
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL||pRoot2==NULL)
            return false;
        bool res = false;
        if(pRoot1->val==pRoot2->val)
               res =  isSubtree(pRoot1,pRoot2);
        if(!res) res = HasSubtree(pRoot1->left,pRoot2);
        if(!res) res = HasSubtree(pRoot1->right,pRoot2);
        return res;        
    }
};