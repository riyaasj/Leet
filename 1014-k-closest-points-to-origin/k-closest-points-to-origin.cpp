class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto p: points) {
            pair<int, vector<int>> temp = {p[0] * p[0] + p[1] * p[1], p};
            pq.push(temp);
            if(size(pq) > k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        } 
        return ans;  
    }
};