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
    �ݹ�Ѱ��ֵΪkey�Ľ��
    ��Ϊ�ӽ��ֱ��ɾ��
    ��ֻ��������ڣ�ɾ����ǰ��㣬��������
    ��ֻ���ҽ����ڣ�ɾ����ǰ��㣬�����ҽ��
    ��������㶼���ڣ���������Ѱ�������Ҷ��㣬������ɾ��
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
