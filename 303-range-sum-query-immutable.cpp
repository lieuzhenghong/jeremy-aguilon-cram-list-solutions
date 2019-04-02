class NumArray {
public:
    vector<int> internal;
    
    NumArray(vector<int> nums) {
        for (auto &n : nums)
        {
            if (internal.size())
            {
                internal.push_back(internal.back() + n);
            }
            else internal.push_back(n);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return internal[j];
        else return internal[j] - internal[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
