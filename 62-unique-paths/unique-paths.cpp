class Solution {
public:
    int f(int m, int n, vector<vector<int>> &v){
        if(m == 0 && n == 0){
            return 1;
        }
        if(m < 0 || n < 0) return 0;
        if(v[m][n] != -1) return v[m][n];
        return v[m][n] = f(m - 1, n, v) + f(m, n - 1, v);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m, vector<int>(n, -1));
        return f(m - 1, n - 1, v);
    }
};