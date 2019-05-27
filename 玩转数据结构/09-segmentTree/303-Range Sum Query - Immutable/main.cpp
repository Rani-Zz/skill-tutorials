class segmentTree{
private:
    vector<int> tree;
    vector<int> data;
    void treeBuild(int treeIndex,int l,int r)
    {
        if(l==r)
        {
            tree[treeIndex] =  data[l];
            return;
        }
        
        int mid = l+(r-l)/2;
        treeBuild(treeIndex*2+1,l,mid);
        treeBuild(treeIndex*2+2,mid+1,r);
        
        tree[treeIndex] = tree[treeIndex*2+1] + tree[treeIndex*2+2];
    }
    
    int query(int treeIndex,int lbound,int rbound,int l,int r)
    {
        if(lbound==l&& rbound==r)
            return tree[treeIndex];
        
        int mid = (lbound+rbound)/2;
        if(r<=mid)
            return query(treeIndex*2+1,lbound,mid,l,r);
        if(l>=mid+1)
            return query(treeIndex*2+2,mid+1,rbound,l,r);
        
        return query(treeIndex*2+1,lbound,mid,l,mid)+
            query(treeIndex*2+2,mid+1,rbound,mid+1,r);
    }
public:
    segmentTree(const vector<int>& nums)
    {
        if(nums.empty())
            return;
        
        data = nums;
        
        int size = nums.size()*4;
        tree = vector<int>(size,-1);
        
        treeBuild(0,0,data.size()-1);
    }
    
    int query(int l,int r)
    {
        assert(l >= 0 && l < data.size());
        assert(r >= 0 && r < data.size());
        return query(0,0,data.size()-1,l,r);
    }   
    
};
class NumArray {
private:
    segmentTree tree;
public:
    /**
    *setmentTree
    */
    NumArray(vector<int>& nums):tree(nums) {
    }
    
    int sumRange(int i, int j) {
        int res = tree.query(i,j);
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
