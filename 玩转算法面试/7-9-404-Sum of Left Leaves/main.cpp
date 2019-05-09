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
private:
    int sumLeft(TreeNode* root,bool isleft)
    {
        if(root==NULL) return 0;
        if(isleft&&root->left==NULL&&root->right==NULL)
        {
            return root->val;
        }
        
        return sumLeft(root->left,true)+sumLeft(root->right,false);
    }
public:
    /**
    *��͵������������� ���Ǹ��ڵ�
    *������ʱ����Ա���Ƿ���������
    *�������������Ƿ�Ϊ���ж��Ƿ�Ϊ���ڵ�
    */
    int sumOfLeftLeaves(TreeNode* root) {
        return sumLeft(root,false);
    }
};
