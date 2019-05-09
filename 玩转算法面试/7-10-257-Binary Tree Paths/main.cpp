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
    vector<string> res;
    void printPath(TreeNode* root,string s)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            res.push_back(s);
            return ;
        }
        
        if(root->left)
            printPath(root->left,s+"->"+to_string(root->left->val));
        if(root->right)
            printPath(root->right,s+"->"+to_string(root->right->val));
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return res;
        printPath(root,to_string(root->val));
        return res;
    }
};
