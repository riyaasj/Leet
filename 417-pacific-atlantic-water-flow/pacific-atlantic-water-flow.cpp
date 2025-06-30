class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> heights){
        visited[i][j] = 1;
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(auto d: dir){
            int x = i + d[0],  y = j + d[1];
            if(x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size() && heights[x][y] >= heights[i][j] && !visited[x][y]){
                dfs(x, y, visited, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> atlantic(heights.size(), vector<int>(heights[0].size(), 0)), pacific(heights.size(), vector<int>(heights[0].size(), 0)), res;
        for(int i = 0; i < m; i++) dfs(i, 0, pacific, heights);        
        for(int j = 0; j < n; j++) dfs(0, j, pacific, heights); 
        for(int i = 0; i < m; i++) dfs(i, n - 1, atlantic, heights);    
        for(int j = 0; j < n; j++) dfs(m - 1, j, atlantic, heights);    
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(atlantic[i][j] && pacific[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};