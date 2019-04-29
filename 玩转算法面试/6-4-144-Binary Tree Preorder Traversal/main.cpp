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
    *�ǵݹ� ǰ����� ������
    *��ջ ���� ��ջ ���� ����
    */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty())
        {
            TreeNode* p = stk.top();
            stk.pop();
            res.push_back(p->val);
            if(p->right)
                stk.push(p->right);
            if(p->left)
                stk.push(p->left);
        }
        
        return res;
    }
};
