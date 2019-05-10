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
    ���������������ǰ����Ϊsum��·���������ݹ�Ѱ�ҵ���sum-node->val�Ľ��
             ��������ǰ����Ϊsum��·���������������ݹ�Ѱ��
                                       ...���������ݹ�Ѱ��
    */
    //���ز�������ǰ�ڵ㣬����Ϊsum��·������
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        int res = findPath(root,sum);
        res+=pathSum(root->left,sum);
        res+=pathSum(root->right,sum);
        
        return res;
        
    }
private:
    //������ǰ����Ϊsum��·���������ݹ�Ѱ�ҵ���sum-node->val�Ľ��
    int findPath(TreeNode* root,int sum)
    {
        if(root==NULL)
            return 0;
        
        int res = 0;
        if(root->val==sum)
            res+=1;
        
        res+=findPath(root->left,sum-root->val);
        res+=findPath(root->right,sum-root->val);
        
        return res;
    }
};
