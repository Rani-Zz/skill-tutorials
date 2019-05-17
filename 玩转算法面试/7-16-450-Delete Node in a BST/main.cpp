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
    递归寻找值为key的结点
    若为子结点直接删除
    若只有左结点存在，删除当前结点，返回左结点
    若只有右结点存在，删除当前结点，返回右结点
    若两个结点都存在，在右子树寻找最左的叶结点，交换后删除
    */
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
       
        if(root->val == key)
        {

            if(root->left&&root->right)
            {
              
                TreeNode* bt = root->right;
                while(bt->left)
                {
                    bt = bt->left;
                }
                swap(root->val,bt->val);
                delete bt;
                return root;                
            }
            else if(root->left)
            {
                return root->left;
            }else if(root->right)
            {
                return root->right;
            }else
            {
               
                delete root;
                return NULL;
            }
            
        }else if(key < root->val)
            root->left =  deleteNode(root->left,key);
        else
            root->right =  deleteNode(root->right,key);
          
        return root;
    }
};
