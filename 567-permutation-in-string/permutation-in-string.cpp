class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m;
        for(char x: s1){
            m[x]++;
        }
        int i = 0, j = s1.size() - 1, res = 0;
        while(j < s2.size()){
            unordered_map<char, int> temp = m;
            for(int k = i; k <= j; k++){
                if(temp[s2[k]] == 0){
                    break;
                }
                temp[s2[k]]--;
            }
            int flag = 1;
            for(auto a: temp){
                if(a.second > 0){
                    flag = 0;
                    break;
                }
            }
            res += flag;
            j++;
            i++;
        }
        return res;
    }
};