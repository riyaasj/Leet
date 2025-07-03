class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, res = 0;
        vector<int> count(2, 0);
        for(int right = 0; right < nums.size(); right++){
            count[nums[right]]++;
            while(count[0] > k){
                count[nums[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};