class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.back() > nums.front()) return nums[0];
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int m = (left + right) / 2;
            if(nums[m] > nums[right]){
                left = m + 1;
            }
            else{
                right = m;
            }
        }
        return nums[left];
    }
};