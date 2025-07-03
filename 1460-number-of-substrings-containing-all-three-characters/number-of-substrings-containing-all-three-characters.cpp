class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> m;
        int left = 0, count = 0;
        for(int right = 0; right < s.size(); right++){
            m[s[right]]++;
            while(m['a'] && m['b'] && m['c']){
                count += s.size() - right;
                m[s[left]]--;
                left++;
            }
        }
        return count;
    }
};