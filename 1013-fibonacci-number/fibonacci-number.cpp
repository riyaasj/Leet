class Solution {
public:
    int solve(vector<int> &val, int n){
        if(n < 0) return 0;
        if(n <= 1) return n;
        if(val[n] != -1) return val[n];
        return val[n] = solve(val, n - 1) + solve(val, n - 2);
    }
    int fib(int n) {
        vector<int> val(n + 1, -1);

        return solve(val, n);
    }
};