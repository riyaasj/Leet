class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int i = 0;
        for(char c: s){
            if(c =='('){
                if(i != 0){
                    res += c;
                }
                i++;
            }
            else{
                if(i != 1){
                    res += c;
                }
                i--;
            }
        }
        return res;
    }
};