class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = nums[0];
        for(int i = 1; i <= nums.size() - 1; i++){
            int s1 = nums[i], s2 = b;
            if(i > 1) s1 += a;
            int next = max(s1, s2);
            a = b;
            b = next;
        }
        return b;
    }
};