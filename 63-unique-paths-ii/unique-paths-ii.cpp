class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < m; i++){
            vector<int> temp(n, 0);
            if(obstacleGrid[i][0] != 1) temp[0] = dp[0];
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] != 1) temp[j] = temp[j - 1] + dp[j];
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};