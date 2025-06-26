class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(pow(2, nums.size()));
        for(int i = 0; i < pow(2, nums.size()); i++){
            for(int j = 0; j < nums.size(); j++){
                if((i >> j) % 2){
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};