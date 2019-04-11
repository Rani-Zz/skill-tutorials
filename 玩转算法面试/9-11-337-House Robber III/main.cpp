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
    vector<int> dfs(TreeNode* root)
    {
        if(root==NULL) return vector<int>(2,0);
        
        vector<int> lf = dfs(root->left);
        vector<int> lr = dfs(root->right);
        
        vector<int> res(2,0);
        res[0] = root->val+lf[1]+lr[1]; //下标为0存放偷这个结点的值
        res[1] = max(lf[0],lf[1])+max(lr[0],lr[1]); //下标为1存放不偷这个结点的值
        
        return res;
    }
public:
    /**
    *变成在两个子树中找最大值
    *后序遍历 返回遍历到每个结点可获得的最大值？
    *每个结点返回两个值 偷这个结点 和不偷这个结点 最优子结构
    *偷这个结点,不能偷左右 node->val+ node->left不偷+node->right不偷
    *不偷这个结点：可以偷左右，也可以不偷左右，max(node->left偷，node->left不偷)
    *                                     +max(node->right偷，node->right不偷)
    */
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0],res[1]);
    }
};
