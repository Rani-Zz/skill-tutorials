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
    TreeNode* insertBST(vector<int> nums, int i,int j)
    {
        if(i==j) return NULL;
        int mid = (j+i)/2;
        
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = insertBST(nums,i,mid);
        root->right = insertBST(nums,mid+1,j);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
            int i = 0,j = nums.size();
            return insertBST(nums,i,j);
    }
};
