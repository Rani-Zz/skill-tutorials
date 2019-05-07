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
    int mindepth(TreeNode* root,int len)
    {
        if(root->left==NULL&&root->right==NULL)
            return len;
        int l = root->left?mindepth(root->left,len+1):INT_MAX;
        int r = root->right?mindepth(root->right,len+1):INT_MAX;
        return min(l,r);
    }
public:
    /**
    *������� ��������������Ƚ�С��
    *���������ڵ�ֹͣ
    *���ǿս����Ȳ��ܷ���0������ΪNULLʱ����INT_MAX
    */
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        
        return mindepth(root,1);
    }
};
