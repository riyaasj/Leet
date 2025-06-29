class Solution {
public:
    int solve(int n, unordered_map<int, int> &m){
        if(n == 0){
            return 0;
        }
        if(!m[n]){
            m[n] = solve(n - 1, m) + solve(n - 2, m);
        }
        return m[n];
    }
    int fib(int n) {
        unordered_map<int, int> m;
        m[1] = 1;
        return solve(n, m);
    }
};