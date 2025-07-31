class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p = 1, res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                p = 1;
                res = max(res, 0);
            }
            else{
                p *= nums[i];
                res = max(res, p);
            }
        }
        p = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] == 0){
                p = 1;
                res = max(res, 0);
            }
            else{
                p *= nums[i];
                res = max(res, p);
            }
        }
        return res;
    }
};