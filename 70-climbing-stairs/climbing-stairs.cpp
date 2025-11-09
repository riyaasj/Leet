class Solution {
public:
    int f(vector<int> &dp, int n){
        if(dp[n] != -1) return dp[n];
        return dp[n] = f(dp, n - 1) + f(dp, n - 2);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        if(n >= 1) dp[1] = 1;
        return f(dp, n);
    }
};