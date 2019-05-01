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
    *层序遍历 queue
    *返回每层最后一个
    */
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> tmp;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            TreeNode* p = q.front().first;
            int l = q.front().second;
            q.pop();
            if(l==tmp.size())
                tmp.push_back(vector<int>{});
            tmp[l].push_back(p->val);
            if(p->left)
                q.push(make_pair(p->left,l+1));
            if(p->right)
                q.push(make_pair(p->right,l+1));
        }
        
        for(auto t:tmp)
        {
            res.push_back(t.back());
        }
        
        return res;
    }
};
