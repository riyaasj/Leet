class Solution {
public:
    int robh(vector<int>& nums) {
        int a = 0, b = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int temp = max(a + nums[i], b);
            a = b;
            b = temp;
        }
        return b;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int a = 0, b1 = nums[0];
        for(int i = 1; i < nums.size() - 1; i++){
            int temp = max(a + nums[i], b1);
            a = b1;
            b1 = temp;
        }
        a = 0;
        int b2 = nums[1];
        for(int i = 2; i < nums.size(); i++){
            int temp = max(a + nums[i], b2);
            a = b2;
            b2 = temp;
        }
        return max(b1, b2);
    }
};