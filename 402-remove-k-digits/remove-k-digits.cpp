class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        stack<char> s;
        for(int i = 0; i < num.size(); i++){
            while(!s.empty() && k > 0 && s.top() > num[i]){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k--){
            s.pop();
        }
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        if(res == "") return "0";
        int i = 0;
        while(res[i] == '0' && i < res.size()){
            i++;
        }
        res = res.substr(i, res.size() - i);
        if(res == "") return "0";
        return res;
    }
};