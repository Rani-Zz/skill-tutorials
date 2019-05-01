/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct command{
    string s;
    TreeNode* node;
    command(string s,TreeNode* p):s(s),node(p){}
};
class Solution {
public:
    /**
    *Õ» ¸ù ×ó ÓÒ
    */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<command> stack;
        stack.push(command("go",root));
        while(!stack.empty())
        {
            command c = stack.top();
            stack.pop();
            if(c.s=="print") res.push_back(c.node->val);
            else
            {
                if(c.node->right)
                    stack.push(command("go",c.node->right));
                if(c.node->left)
                    stack.push(command("go",c.node->left));
                stack.push(command("print",c.node));
            }
        }
        
        return res;
    }
};
