class NumArray {
private:
    vector<int> sum;
public:
    /**
    *sum[i]:��ʾsum[0,...,i]
    *���� sum[i,...,j] = sum[j]-sum[i-1]
    */
    NumArray(vector<int>& nums) {
        sum.push_back(0);
        for(auto i:nums)
            sum.push_back(sum.back()+i);
    }
    
    int sumRange(int i, int j) {
        i++;
        j++;
        return sum[j]-sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
