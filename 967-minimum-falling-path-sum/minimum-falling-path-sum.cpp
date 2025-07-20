class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix.back();
        for(int i = n - 2; i >= 0; i--){
            vector<int> temp(n);
            for(int j = 0; j < n; j++){
                if(j == 0){
                    temp[j] = matrix[i][j] + min(dp[j], dp[j + 1]);
                }
                else if(j == n - 1){
                    temp[j] = matrix[i][j] + min(dp[j], dp[j - 1]);
                }
                else{
                    temp[j] = matrix[i][j] + min(dp[j - 1], min(dp[j], dp[j + 1]));
                }
            }
            dp = temp;
        }
        int res = INT_MAX;
        for(int i: dp){
            res = min(res, i);
        }
        return res;
    }
};