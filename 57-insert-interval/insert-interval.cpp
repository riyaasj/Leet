class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int s = newInterval[0], l = newInterval[1], flag = 0;
        for(auto x: intervals){
            if(x[0] < newInterval[0] && x[1] < newInterval[0]){
                res.push_back(x);
            }
            else if(x[0] > newInterval[1] && x[1] > newInterval[1]){
                if(flag == 0){
                    res.push_back({s, l});
                    flag = 1;
                }
                res.push_back(x);
            }
            else{
                s = min(s, x[0]);
                l = max(l, x[1]);
            }
        }
        if(flag == 0){
            res.push_back({s, l});
        }
        return res;
    }
};