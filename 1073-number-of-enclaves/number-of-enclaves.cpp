class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j){
        grid[i][j] = 0;
        vector<vector<int>> distances = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(auto d: distances){
            if(i + d[0] >= 0 && i + d[0] < grid.size() && j + d[1] >= 0 && j + d[1] < grid[0].size()){
                if(grid[i + d[0]][j + d[1]] == 1){
                    dfs(grid, i + d[0], j + d[1]);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1){
                    if(grid[i][j] == 1){
                        dfs(grid, i, j);
                    }
                }
            }
        }
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]) res++;
            }
        }
        return res;
    }
};