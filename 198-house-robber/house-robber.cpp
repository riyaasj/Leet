class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int a = nums[0], b = max(nums[0], nums[1]);
        for(int i = 2; i <= nums.size() - 1; i++){
            int next = max(a + nums[i], b);
            a = b;
            b = next;
        }
        return b;
    }
};