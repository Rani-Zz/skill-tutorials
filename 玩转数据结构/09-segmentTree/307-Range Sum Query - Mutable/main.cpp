class segmentTree{
private:
    vector<int> tree;
    vector<int> data;
    void buildTree(int index,int lbound,int rbound)
    {
        if(lbound==rbound)
        {
            tree[index] = data[lbound];
            return;
        }
        
        int mid = (lbound + rbound)/2;
        buildTree(index*2+1,lbound,mid);
        buildTree(index*2+2,mid+1,rbound);
        
        tree[index] = tree[index*2+1]+tree[index*2+2];
        return;
    }
    int query(int index,int lbound,int rbound,int l,int r)
    {
        if(lbound==l&&rbound==r)
        {
            return tree[index];
        }
        
        int mid = (lbound+rbound)/2;
        if(r<=mid)
        {
            return query(index*2+1,lbound,mid,l,r);
        }
        if(l>=mid+1)
        {
            return query(index*2+2,mid+1,rbound,l,r);
        }
        
        return query(index*2+1,lbound,mid,l,mid)+
            query(index*2+2,mid+1,rbound,mid+1,r);
    }
    void update(int treeIndex,int lbound,int rbound,int index,int val)
    {
        if(lbound==rbound)
        {
            tree[treeIndex] = val;
            return;
        }   
        
        int mid = (lbound+rbound)/2;
        if(index<=mid)
            update(treeIndex*2+1,lbound,mid,index,val);
        if(index>=mid+1)
            update(treeIndex*2+2,mid+1,rbound,index,val);
        
        tree[treeIndex] = tree[treeIndex*2+1]+ tree[treeIndex*2+2];
        return;
    }
public:
    segmentTree(const vector<int>& nums):data(nums)
    {
        if(nums.empty())
            return;
        int size = data.size()*4;
        tree = vector<int>(size,0);
        buildTree(0,0,data.size()-1);
        return;
    }
    
    int query(int i,int j)
    {
        assert(i>=0&&i<data.size());
        assert(j>=0&&j<data.size());
        return query(0,0,data.size()-1,i,j);
    }
    
    void update(int index,int val)
    {
        assert(index >= 0 && index < data.size());
        data[index] = val;
        update(0,0,data.size()-1,index,val);
        return;
    }
};
class NumArray {
    segmentTree tree;
public:
    NumArray(vector<int>& nums):tree(nums) {
    }
    
    void update(int i, int val) {
        return tree.update(i,val);
    }
    
    int sumRange(int i, int j) {
        return tree.query(i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
