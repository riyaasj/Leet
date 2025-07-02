class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int t1 = 0;
        for(int i = 0; i <= nums.size(); i++){
            t1 = t1 ^ i;
        }
        for(int i: nums){
            t1 = t1 ^ i;
        }
        return t1;
    }
};