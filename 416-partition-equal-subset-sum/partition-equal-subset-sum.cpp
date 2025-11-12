class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i: nums){
            sum += i;
        }
        if(sum % 2) return false;
        sum = sum / 2;
        vector<bool> prev(sum + 1, false), curr(sum + 1, false);
        prev[0] = true;
        if(nums[0] <= sum) prev[nums[0]] = true;

        for(int i = 1; i < nums.size(); i++){
            for(int j = 1; j <= sum; j++){
                bool noTake = prev[j];
                bool take = false;
                if(nums[i] <= j) take = prev[j - nums[i]];
                curr[j] = noTake || take;
            }
            prev = curr;
        }
        return prev[sum];
    }
};