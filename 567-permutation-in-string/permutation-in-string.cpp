class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;

        vector<int> m(26, 0), t(26, 0);

        for(int i = 0; i < s1.size(); i++){
            t[s2[i] - 'a']++;
            m[s1[i] - 'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++){
            if(t[i] == m[i]) matches++;
        }

        if(matches == 26) return true;

        int i = 0, j = s1.size() - 1;
        while(j < s2.size() - 1){
            t[s2[i] - 'a']--;
            if(t[s2[i] - 'a'] == m[s2[i] - 'a']){
                matches++;
            }
            else if(t[s2[i] - 'a'] == m[s2[i] - 'a'] - 1){
                matches--;
            }
            i++;

            j++;
            t[s2[j] - 'a']++;
            if(t[s2[j] - 'a'] == m[s2[j] - 'a']){
                matches++;
            }
            else if(t[s2[j] - 'a'] == m[s2[j] - 'a'] + 1){
                matches--;
            }
            if(matches == 26) return true;
        }
        return false;
    }
};