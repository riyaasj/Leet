class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<stack<int>> freq(nums.size() + 1);
        unordered_map<int, int> m;
        for(int i: nums){
            m[i]++;
        }
        for(auto i: m){
            freq[i.second].push(i.first);
        }
        vector<int> res;
        for (int i = freq.size() - 1; i >= 0 && k > 0; i--) {
            while (!freq[i].empty() && k > 0) {
                res.push_back(freq[i].top());
                freq[i].pop();
                k--;
            }
        }

        return res;
    }
};