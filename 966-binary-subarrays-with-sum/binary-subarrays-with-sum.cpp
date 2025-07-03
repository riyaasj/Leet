class Solution {
public:
    int solve(vector<int> nums, int goal){
        if(goal < 0){
            return 0;
        }
        int left = 0, right = 0, total = 0, count = 0;
        while(right < nums.size()){
            total += nums[right];
            while(total > goal){
                total -= nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};