class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], prod = 1, f = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                prod = 1;
                f = 1;
            }
            else{
                prod *= nums[i];
                res = max(res, prod);
            }
        }
        prod = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] == 0){
                prod = 1;
            }
            else{
                prod *= nums[i];
                res = max(res, prod);
            }
        }
        if(res < 0 && f == 1) return 0;
        return res;
    }
};