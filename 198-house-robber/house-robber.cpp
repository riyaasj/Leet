class Solution {
public:
    int solve(vector<int> &nums, int k, vector<int> &v){
        if(k == 0) return 0;
        if(k == 1) return nums[0];
        if(v[k] != -1) return v[k];
        return v[k] = max(solve(nums, k - 2, v) + nums[k - 1], solve(nums, k - 1, v));
    }
    int rob(vector<int>& nums) {
        vector<int> v(nums.size() + 1, -1);
        return solve(nums, nums.size(), v);
    }
};