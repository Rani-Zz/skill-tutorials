/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    /**
    *���������ؿ�
    *���������ڣ���������������ߵĽ��
    *�Ǹ����
    *�����ǰ���Ϊ���������㣬���ظ���㣻����������ظ��������(����)
    */
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
            return NULL;
        if(pNode->right!=NULL)
        {
            TreeLinkNode* p = pNode->right;
            while(p->left!=NULL)
                p = p->left;
            return p;
        }
        
        while(pNode->next!=NULL)
        {
            TreeLinkNode* parent = pNode->next;
            if(parent->left == pNode)
                return parent;
            pNode = pNode->next;
        }
        
        return NULL;
    }
};