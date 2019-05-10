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
    三种情况：包含当前结点和为sum的路径个数，递归寻找等于sum-node->val的结点
             不包含当前结点和为sum的路径个数，左子树递归寻找
                                       ...，右子树递归寻找
    */
    //返回不包含当前节点，但和为sum的路径个树
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        int res = findPath(root,sum);
        res+=pathSum(root->left,sum);
        res+=pathSum(root->right,sum);
        
        return res;
        
    }
private:
    //包含当前结点和为sum的路径个数，递归寻找等于sum-node->val的结点
    int findPath(TreeNode* root,int sum)
    {
        if(root==NULL)
            return 0;
        
        int res = 0;
        if(root->val==sum)
            res+=1;
        
        res+=findPath(root->left,sum-root->val);
        res+=findPath(root->right,sum-root->val);
        
        return res;
    }
};
