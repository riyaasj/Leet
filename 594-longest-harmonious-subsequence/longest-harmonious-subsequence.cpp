class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i: nums){
            m[i]++;
        }
        int res = 0;
        for(auto x: m){
            if(m.count(x.first + 1)){
                res = max(res, x.second + m[x.first + 1]);
            }
        }
        return res;
    }
};