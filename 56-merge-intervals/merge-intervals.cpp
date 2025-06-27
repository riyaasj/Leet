class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int s = intervals[0][0], l = intervals[0][1];
        for(auto x: intervals){
            if(x[0] <= l || (s <= x[0] && x[1] <= l) || (s >= x[0] && x[1] >= l)){
                s = min(s, x[0]);
                l = max(l, x[1]);
            }
            else{
                res.push_back({s, l});
                s = x[0];
                l = x[1];
            }
        }
        res.push_back({s, l});
        return res;
    }
};