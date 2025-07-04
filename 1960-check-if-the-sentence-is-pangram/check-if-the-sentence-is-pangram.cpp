class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> alphabet(26, 0);
        int m = 0;
        for(char c: sentence){
            if(alphabet[c - 'a'] == 0){
                alphabet[c - 'a'] = 1;
                m++;
            }
        }
        return m == 26;
    }
};