class Solution {
public:
    int f(int m, int n, vector<vector<int>> &v, vector<vector<int>> &obstacleGrid){
        if(m == 0 && n == 0){
            return 1;
        }
        if(m < 0 || n < 0 || obstacleGrid[m][n] == 1) return 0;
        if(v[m][n] != -1) return v[m][n];
        return v[m][n] = f(m - 1, n, v, obstacleGrid) + f(m, n - 1, v, obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> v(m, vector<int>(n, -1));
        return f(m - 1, n - 1, v, obstacleGrid);
    }
};