class NumArray {
public:
    vector<int> tree;
    int pow2;
    int exp;
    
    pair<int, int> nearest_pow2(int n)
    {
        for (int i = 0; i < 32; i++) {
            if (pow(2,i) < n) continue;
            else return make_pair(pow(2,i), i);
        }
        return make_pair(n, -1);
    }
    
    NumArray(vector<int> nums) {
        pow2 = nearest_pow2(nums.size()).first;
        exp = nearest_pow2(nums.size()).second;
        
        int L = 0;
        int R = nums.size()-1;
        
        tree.resize(2*pow2-1, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            int idx = i + pow2 - 1;
            tree[idx] = nums[i];
        }
        
        for (int n = 0; n < nums.size(); n++) {
            update(n, nums[n]); 
        }
        
    }
    
    void update(int i, int val) {
        
        int idx = i + pow2 - 1;
        tree[idx] = val;
        
        for (int i = 1; i <= exp; i++) {
            idx = (idx-1) / 2;
            tree[idx] = tree[idx * 2 + 1] + tree[idx * 2 + 2];
        }         
        
    }
    
    void print_tree() {
        int width = 1;
        int counter = 0;
        for (auto &n : tree) {
            counter++;
            cout << n << " ";
            if (counter >= width) {
                cout << endl;
                width *= 2;
                counter = 0;
            }
        }
        cout << endl;
    }
    
    int queryTree(int root, int l, int r, int i, int j) {
        //cout << "querying node " << root << " with boundaries " << l << ", " << r << " and range sum " << i << ", " << j << endl;
        if (l > i && r < j) {
            return tree[root];
        }
        else if (r < i || l > j) {
            return 0;
        }
        else {
            if (l == r) return tree[root];
            else {
                return queryTree(root*2+1, l, (l+r)/2, i, j) +
                       queryTree(root*2+2, (l+r)/2 + 1, r, i, j);
            }
        }
    }
    
    int sumRange(int i, int j) {
        //print_tree();
        return queryTree(0, 0, (tree.size()- 1)/2, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
