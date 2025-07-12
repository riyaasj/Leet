class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0)), res(mat.size(), vector<int>(mat[0].size(), 0)), distances = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        queue<vector<int>> q;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i, j, 0});
                    visited[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            int i = curr[0], j = curr[1], dist = curr[2];
            res[i][j] = dist;
            for(auto d: distances){
                if(i + d[0] >= 0 && i + d[0] < mat.size() && j + d[1] >= 0 && j + d[1] < mat[0].size() && !visited[i + d[0]][j + d[1]]){
                    visited[i + d[0]][j + d[1]] = 1;
                    q.push({i + d[0], j + d[1], dist + 1});
                }
            }
        }
        return res;
    }
};