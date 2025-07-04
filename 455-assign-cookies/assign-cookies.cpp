class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0){
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cookie = 0, num = 0;

        for(int greed = 0; greed < g.size(); greed++){
            while(cookie < s.size() && s[cookie] < g[greed]){
                cookie++;
            }
            if(cookie == s.size()){
                return num;
            }
            num++;
            cookie++;
        }
        return num;
    }
};