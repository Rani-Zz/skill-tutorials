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
    void find(TreeNode* root,int exp,vector<int> p)
    {
        if(root==NULL)
            return;
        p.push_back(root->val);
        exp-=root->val;
        if(exp==0&&root->left==NULL&&root->right==NULL)
        {
            res.push_back(p);
            return;
        }
        find(root->left,exp,p);
        find(root->right,exp,p);
        p.pop_back();
        return;
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL)
            return vector<vector<int>>();
        vector<int> p;
        find(root,expectNumber,p);
        return res;
    }
};
