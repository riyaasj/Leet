class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> pq;
        for(int i = 0; i < points.size(); i++) {
            vector<int> temp = {points[i][0] * points[i][0] + points[i][1] * points[i][1], i};
            pq.push(temp);
            if(size(pq) > k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(points[pq.top()[1]]);
            pq.pop();
        } 
        return ans;  
    }
};