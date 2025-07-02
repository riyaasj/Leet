class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n != 1){
            int t = 0;
            while(n){
                t += (n % 10) * (n % 10);
                n = n / 10;
            }
            if(s.find(t) != s.end()){
                return false;
            }
            s.insert(t);
            n = t;
        }
        return true;
    }
};