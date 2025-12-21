class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = 0;
        string res = "";
        for(char i: s){
            if(i == '('){
                n++;
                if(n == 1){
                    continue;
                }
                res += i;
            }
            else{
                n--;
                if(n == 0){
                    continue;
                }
                res += i;
            }
        }
        return res;
    }
};