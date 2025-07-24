class Solution {
public:
    bool f(vector<int> &nums, int target){
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        if(nums[0] <= target){
            dp[nums[0]] = true;
        }
        for(int i = 1; i < nums.size(); i++){
            vector<bool> v(target + 1, false);
            v[0] = 1;
            for(int j = 1; j <= target; j++){
                int a = dp[j];
                int b = false;
                if(nums[i] <= j){
                    b = dp[j - nums[i]];
                }
                v[j] = a || b;
            }
            dp = v;
        }
        return dp[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i: nums){
            sum += i;
        }
        if(sum % 2) return false;
        else{
            return f(nums, sum / 2);
        }
    }
};