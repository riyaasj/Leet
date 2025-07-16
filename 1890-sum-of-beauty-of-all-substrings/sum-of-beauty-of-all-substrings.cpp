class Solution {
public:
    int beautySum(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_map<char, int> m;
            m[s[i]]++;
            int most = 1, least = 1;
            for(int j = i + 1; j < s.size(); j++){
                m[s[j]]++;
                int most = INT_MIN;
                int least = INT_MAX;
                
                for (auto &[ch, freq] : m) {
                    most = max(most, freq);
                    least = min(least, freq);
                }
                res += most - least;
            }
        }
        return res;
    }
};