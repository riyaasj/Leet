class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int e = intervals[0][1], res = 1;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= e){
                e = intervals[i][1];
                res++;
            }
        }
        return intervals.size() - res;
    }
};