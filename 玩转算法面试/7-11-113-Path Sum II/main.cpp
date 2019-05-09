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
    vector<vector<int>> res;
    void findPath(TreeNode* root,int sum,vector<int> p)
    {
        if(root==NULL) return;
        sum-=root->val;
        p.push_back(root->val);
        if(root->left==NULL&&root->right==NULL&&sum==0)
        {
            res.push_back(p);
            return;
        }
        findPath(root->left,sum,p);
        findPath(root->right,sum,p);
        p.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return res;
        vector<int> p;
        findPath(root,sum,p);
        return res;
    }
};
