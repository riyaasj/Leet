class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, res = 0, z = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0) z++;
            while(z > k){
                if(nums[left] == 0) z--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};