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
    *∑«µ›πÈ
    *”√queue BFS
    */
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty())
        {
            TreeNode* p1 = q.front();
            q.pop();
            TreeNode* p2 = q.front();
            q.pop();
            if(p1==NULL&&p2==NULL) continue;
            if(p1==NULL||p2==NULL) return false;
            if(p1->val!=p2->val)
            {
                return false;
            }   
            
            q.push(p1->left);
            q.push(p2->right);
            q.push(p1->right);
            q.push(p2->left);
        }
        
        return true;
    }
};
