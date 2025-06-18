class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                suffix[i] = 1;
            }
            else{
                suffix[i] = suffix[i + 1] * nums[i + 1];
            }
        }
        int x = 1;
        for(int i = 0; i < nums.size(); i++){
            int t = nums[i];
            nums[i] = x * suffix[i];
            x *= t;
        }
        return nums;
    }
};