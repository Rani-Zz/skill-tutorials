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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(root->val==key)
        {
            if(root->left&&root->right)
            {
                TreeNode* p = root->right;
                while(p->left)
                {
                    p = p->left;
                }
                swap(root->val,p->val);
                //注意这一步
                root->right = deleteNode(root->right,p->val);
                return root;
            }else if(root->left)
                return root->left;
            else if(root->right)
                return root->right;
            else
            {
                 delete root;
                 return NULL;
            }
                
        }else if(key<root->val)
        {
            root->left = deleteNode(root->left,key);
        }else
            root->right = deleteNode(root->right,key);
        
        return root;
    }
};
