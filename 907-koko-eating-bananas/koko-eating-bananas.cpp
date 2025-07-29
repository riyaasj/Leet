class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = piles[0];
        for(int i: piles){
            m = max(m, i);
        }
        int l = 1, r = m, res;
        while(l <= r){
            int m = l + (r - l) / 2;
            long long x = 0;
            for (int pile : piles) {
                x += (pile + m - 1) / m;  
            }

            if(x > h){
                l = m + 1;
            }
            else{
                res = m;
                r = m - 1;
            }
        }
        return res;
    }
};