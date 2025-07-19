class Solution {
public:
    int f(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& v){
        if(m < 0 || n < 0){
            return INT_MAX;
        }
        if(m == 0 && n == 0){
            return v[0][0] = grid[0][0];
        }
        if(v[m][n] != -1) return v[m][n];

        int up = f(m - 1, n, grid, v);
        int left = f(m, n - 1, grid, v);
        return v[m][n] = grid[m][n] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> v(m, vector<int>(n, -1));
        return f(m - 1, n - 1, grid, v);
    }
};
