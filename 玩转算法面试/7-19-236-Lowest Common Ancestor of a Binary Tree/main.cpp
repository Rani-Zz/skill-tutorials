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
    *��ʵ���������������
    *���Ҹ� 
    *�����ҵ����ؽ�� ���� root
    *���ҵ� ������
    *���ҵ� ������
    *�ݹ�Ѱ�����Ҷ��ҵ��Ľ��
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left&&right) return root;
        else if(left) return left;
        else if(right) return right;
        else return NULL;
    }
};
