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
private:
    vector<vector<int>> res;
    vector<int> tmp;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL)
            return res;
        tmp.push_back(root->val);
        expectNumber-=root->val;
        if(expectNumber==0&&root->left==NULL&&root->right==NULL)
            res.push_back(tmp);
        if(root->left)
            FindPath(root->left,expectNumber);
        if(root->right)
            FindPath(root->right,expectNumber);
        if(!tmp.empty())
            tmp.pop_back();
        return res;
    }
};