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
public:
    /**
    *≤„–Ú±È¿˙
    */
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot==NULL)
            return res;
        queue<pair<TreeNode*,int>> que;
        que.push(make_pair(pRoot,0));
        while(!que.empty())
        {
            TreeNode* p = que.front().first;
            int i = que.front().second;
            que.pop();
            if(i == res.size())
                res.push_back(vector<int>{});
            res[i].push_back(p->val);
            
            if(p->left)
                que.push(make_pair(p->left,i+1));
            if(p->right)
                que.push(make_pair(p->right,i+1));
        }
        
        return res;
    }
    
};