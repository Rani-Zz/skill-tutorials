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
    *层序遍历 quede reverse
    *用两个栈 cur = 0 next = 1
    *cur 为偶数 next入栈 左 右
    *cur 为奇数 next入栈 右 左
    *cur 出栈完 再看next
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        stack<pair<TreeNode*,int>> s[2];
        int cur = 0;
        int next = 1;
        s[cur].push(make_pair(root,0));
        while(!s[cur].empty())
        {
            TreeNode* p = s[cur].top().first;
            int l = s[cur].top().second;
            s[cur].pop();
            if(l==res.size())
                res.push_back(vector<int>{});
            res[l].push_back(p->val);
            if(cur%2==0)
            {
                if(p->left)
                    s[next].push(make_pair(p->left,l+1));
                if(p->right)
                    s[next].push(make_pair(p->right,l+1));
            }else
            {
                if(p->right)
                    s[next].push(make_pair(p->right,l+1));
                if(p->left)
                    s[next].push(make_pair(p->left,l+1));
            }
            
            if(s[cur].empty())
            {
                cur = 1-cur;
                next = 1-next;
            }
        }
        
        return res;
    }
};
