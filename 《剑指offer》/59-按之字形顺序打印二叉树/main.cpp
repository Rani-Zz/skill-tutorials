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
public:
    /**
    *用两个栈来保存，根节点入栈1
    *打印根节点时，将它的左右结点保存到栈2，奇数层，需要先打印右后打印左，所以入栈顺序应该是先左后右
    *打印栈2中的结点时，把他们的结点保存到栈1，偶数层，需要先打印左后打印右，所以入栈顺序应该先右后左
    */
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot==NULL)
            return res;
        stack<pair<TreeNode*,int>> stack[2];
        int curr = 0;
        int next = 1;
        stack[0].push(make_pair(pRoot,0));
        while(!stack[0].empty()||!stack[1].empty())
        {
            TreeNode* p = stack[curr].top().first;
            int i = stack[curr].top().second;
            stack[curr].pop();
            if(res.size()==i)
                res.push_back(vector<int>{});
            res[i].push_back(p->val);
            
            if(curr==0)
            {
                if(p->left)
                    stack[next].push(make_pair(p->left,i+1));
                if(p->right)
                    stack[next].push(make_pair(p->right,i+1));
            }else{
                if(p->right)
                    stack[next].push(make_pair(p->right,i+1));
                if(p->left)
                    stack[next].push(make_pair(p->left,i+1));                   
            }
            if(stack[curr].empty())
            {
                curr = 1-curr;
                next = 1-next;
            }
        }
        
        return res;
    }
    
};