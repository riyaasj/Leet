class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, res = 0;
        unordered_map<char, int> m;
        while(j < s.size()){
            while(j < s.size() && m[s[j]] == 0){
                m[s[j]]++;
                j++;
            }
            res = max(res, j - i);
            while(m[s[j]] == 1){
                m[s[i]]--;
                i++;
            }
        }
        return res;
    }
};