class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, res = 0, maxFreq = 0;
        vector<int> c(26, 0);
        for(int right = 0; right < s.size(); right++){
            maxFreq = max(maxFreq, ++c[s[right] - 'A']);
            if((right - left + 1) - maxFreq > k){
                c[s[left++] - 'A']--;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};