class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0){
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int greed = 0, num = 0;

        for(int cookie = 0; cookie < s.size(); cookie++){
            if(s[cookie] >= g[greed]){
                num++;
                greed++;
            }
            if(greed == g.size()){
                return num;
            }
        }
        return num;
    }
};