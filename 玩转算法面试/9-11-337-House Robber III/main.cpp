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
    vector<int> dfs(TreeNode* root)
    {
        if(root==NULL) return vector<int>(2,0);
        
        vector<int> lf = dfs(root->left);
        vector<int> lr = dfs(root->right);
        
        vector<int> res(2,0);
        res[0] = root->val+lf[1]+lr[1]; //�±�Ϊ0���͵�������ֵ
        res[1] = max(lf[0],lf[1])+max(lr[0],lr[1]); //�±�Ϊ1��Ų�͵�������ֵ
        
        return res;
    }
public:
    /**
    *��������������������ֵ
    *������� ���ر�����ÿ�����ɻ�õ����ֵ��
    *ÿ����㷵������ֵ ͵������ �Ͳ�͵������ �����ӽṹ
    *͵������,����͵���� node->val+ node->left��͵+node->right��͵
    *��͵�����㣺����͵���ң�Ҳ���Բ�͵���ң�max(node->left͵��node->left��͵)
    *                                     +max(node->right͵��node->right��͵)
    */
    int rob(TreeNode* root) {
        vector<int> res = dfs(root);
        return max(res[0],res[1]);
    }
};
