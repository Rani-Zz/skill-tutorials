/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
private:
    vector<int> buf;
    void dfs1(TreeNode* root)
    {
        if(root==NULL)
        {
            buf.push_back(0xFFFFFFFF);
            return;
        }
        buf.push_back(root->val);
        dfs1(root->left);
        dfs1(root->right);
    }
    TreeNode* dfs2(int* &p)
    {
        if(*p==0xFFFFFFFF)
        {
            p++;
            return NULL;
        }
        TreeNode *node = new TreeNode(*p);
        p++;
        node->left = dfs2(p);
        node->right = dfs2(p);
        return node;
    }
public:
    /**
    *���л��ǽ�����������ַ����������л��Ǹ����ַ�������������
    *ǰ������Ӹ���㿪ʼ�����Ը���ǰ��������л���Ȼ���ٷ����л�
    */
    char* Serialize(TreeNode *root) {    
        dfs1(root);
        int *res=new int[buf.size()];
        for(int i = 0;i<buf.size();i++)
            res[i] = buf[i];
        return (char*)res;
    }
    TreeNode* Deserialize(char *str) {
        int *p = (int*)str;
        TreeNode *root = dfs2(p);
        return root;
    }
};