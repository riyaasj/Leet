class Solution {
public:
    int solve(vector<int> nums, int goal){
        if(goal < 0){
            return 0;
        }
        unordered_map<int, int> m;
        int left = 0, right = 0, total = 0, count = 0;
        while(right < nums.size()){
            m[nums[right]]++;
            while(m.size() > goal){
                m[nums[left]]--;
                if(m[nums[left]] == 0){
                    m.erase(nums[left]);
                }
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};