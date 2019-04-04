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
    void inorder(TreeNode *pRoot, TreeNode* &res,int &count,int k)
    {
        if(pRoot==NULL)
            return;
        inorder(pRoot->left,res,count,k);
        if(count>=k) return;
        count++;
        res = pRoot;
        if(count>=k) return;
        inorder(pRoot->right,res,count,k);
    }
public:
    /**
    *ÖÐÐò±éÀú
    */
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL||k<1)
            return NULL;
        int count = 0;
        TreeNode* res = NULL;
        inorder(pRoot,res,count,k);
        if(k>count) return NULL;
        return res;
    }

    
};