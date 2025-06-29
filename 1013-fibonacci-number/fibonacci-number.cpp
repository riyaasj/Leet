class Solution {
public:
    int solve(int n, vector<int> &m){
        if(n == 0 || n == 1){
            return n;
        }
        if(!m[n - 1]){
            m[n - 1] = solve(n - 1, m) + solve(n - 2, m);
        }
        return m[n - 1];
    }
    int fib(int n) {
        vector<int> m(n, 0);
        return solve(n, m);
    }
};