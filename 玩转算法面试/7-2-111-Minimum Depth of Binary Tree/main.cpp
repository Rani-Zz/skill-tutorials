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
    int mindepth(TreeNode* root,int len)
    {
        if(root->left==NULL&&root->right==NULL)
            return len;
        int l = root->left?mindepth(root->left,len+1):INT_MAX;
        int r = root->right?mindepth(root->right,len+1):INT_MAX;
        return min(l,r);
    }
public:
    /**
    *后序遍历 返回左右子树深度较小的
    *遍历到根节点停止 如果不停止就是左右都是INT_MAX,结点深度在参数后加的话会越界
	*所以深度要在遍历结点前就带上，到根结点即左右都为NULL时直接返回 
    *但是空结点深度不能返回0，所以为NULL时返回INT_MAX
    *
    */
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        
        return mindepth(root,1);
    }
};
