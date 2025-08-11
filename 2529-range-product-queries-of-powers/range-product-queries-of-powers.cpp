class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1000000007;
        vector<int> powers;
        int pos = 0;
        while(n){
            if(n % 2){
                powers.push_back(pow(2, pos));
            }
            pos++;
            n = n >> 1;
        }
        vector<int> ans;
        for (auto query : queries) {
            long long cur = 1;
            for (int i = query[0]; i <= query[1]; ++i) {
                cur = (cur * powers[i]) % mod;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};