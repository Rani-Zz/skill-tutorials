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
    *空树，返回空
    *右子树存在，返回右子树最左边的结点
    *非根结点
    *如果当前结点为根结点的左结点，返回根结点；如果不是则重复这个过程(巧妙)
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