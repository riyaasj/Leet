class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n = nums.size(), r = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == key){
                for(int j = max(i - k, r); j <= min(n - 1, i + k); j++){
                    res.push_back(j);
                }
                r = min(n - 1, i + k) + 1;
            }
        }
        return res;
    }
};