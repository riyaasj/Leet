class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> v(m, vector<int>(n, -1));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(i == 0 && j == 0){
                    v[0][0] = grid[0][0];
                }
                else{
                    int a = INT_MAX , b = INT_MAX - 1;
                    if(i > 0) a = v[i - 1][j];
                    if(j > 0) b = v[i][j - 1];
                    v[i][j] = grid[i][j] + min(a, b);
                }
            }
        }

        return v[m - 1][n - 1];
    }
};
