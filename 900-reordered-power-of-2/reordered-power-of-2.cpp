class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> s;
        for(int i = 0; i <= 30; i++){
            string temp = "0000000000";
            int t = pow(2, i);
            while(t){
                temp[t % 10]++;
                t = t / 10;
            }
            s.insert(temp);
        }
        string temp = "0000000000";
        while(n){
            temp[n % 10]++;
            n = n / 10;
        }
        if(s.find(temp) == s.end()) return false;
        return true;
    }
};