/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* p = que.front();
            que.pop();
            res.push_back(p->val);
            
            if(p->left)
                que.push(p->left);
            if(p->right)
                que.push(p->right);
        }
        return res;
            
    }
};