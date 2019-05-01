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
    *层序遍历
    *用队列
    *保存到vector 再reverse
    */
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            TreeNode* p = q.front().first;
            int l = q.front().second;
            q.pop();
            if(l==res.size())
                res.push_back(vector<int>{});
            res[l].push_back(p->val);
            if(p->left)
                q.push(make_pair(p->left,l+1));
            if(p->right)
                q.push(make_pair(p->right,l+1));
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
