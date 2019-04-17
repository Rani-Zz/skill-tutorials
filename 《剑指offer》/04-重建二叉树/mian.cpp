/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* constructTree(vector<int> pre,int pstart,int pend,vector<int> vin,int istart,int iend)
    {
        if(pstart>pend||istart>iend)
            return NULL;
        
        int rootVal = pre[pstart];
        TreeNode* root = new TreeNode(rootVal);
        if(pstart == pend)
            return root;
        
        int mid = istart;
        while(mid<=iend)
        {
            if(vin[mid]==rootVal)
                break;
            mid++;
        }
        //中序遍历vin可以分成两部分 [istart,....,mid-1] [mid+1,...,iend]
        int leftLength = mid - istart;
        //前序遍历也要分成两部分 [psratr+1,pstart+leftLength] [pstart+leftLength+1,pend]
        //构建左子树
        if(leftLength>0)
        {
            root->left = constructTree(pre,pstart+1,pstart+leftLength,vin,istart,mid-1);
        }
        if(pstart+leftLength<pend)
        {
            root->right = constructTree(pre,pstart+leftLength+1,pend,vin,mid+1,iend);
        }
        return root;
    }
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty())
            return NULL;
        return constructTree(pre,0,pre.size()-1,vin,0,vin.size()-1);
    }
};