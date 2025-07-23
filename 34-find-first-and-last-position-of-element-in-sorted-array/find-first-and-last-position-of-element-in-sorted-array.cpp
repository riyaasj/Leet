class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int m = (left + right) / 2;
            if(nums[m] >= target){
                right = m;
            }
            else{
                left = m + 1;
            }
        }
        if(nums[left] == target){
            while(right < nums.size() && nums[right] == target){
                right++;
            }
            return {left, right - 1};
        }
        return {-1, -1};
    }
};