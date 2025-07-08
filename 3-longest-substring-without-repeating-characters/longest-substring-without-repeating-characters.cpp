class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, res = 0;
        unordered_map<char, int> m;
        for(int right = 0; right < s.size(); right++){
            m[s[right]]++;
            while(m[s[right]] == 2){
                m[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};