class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        for(int i = 0; i < grid.size(); i++){
            vector<int> temp(n, 0);
            for(int j = 0; j < grid[0].size(); j++){
                if(i == 0 && j == 0){
                    temp[0] = grid[0][0];
                }
                else{
                    int a = INT_MAX;
                    if(j > 0) a = temp[j - 1];
                    temp[j] = grid[i][j] + min(a, dp[j]);
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};
