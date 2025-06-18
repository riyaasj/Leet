class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int x = nums[0];
        for(int i = 0; i < nums.size() - 1; i++){
            res[i + 1] *= x;
            x *= nums[i + 1];
        }
        x = nums[nums.size() - 1];
        for(int i = nums.size() - 1; i > 0; i--){
            res[i - 1] *= x;
            x *= nums[i - 1];
        }
        return res;
    }
};