class Solution {
public:
    char kthCharacter(int k) {
        string res = "a";
        while(res.size() <= k){
            string temp = "";
            for(char c : res){
                temp += c + 1;
            }
            res += temp;
        }
        return res[k - 1];
    }
};