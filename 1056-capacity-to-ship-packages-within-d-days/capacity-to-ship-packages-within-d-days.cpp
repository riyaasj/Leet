class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = 0, l = weights[0], res;
        for(int i: weights){
            r += i;
            l = max(l, i);
        }
        while(l <= r){
            int mid = l + (r - l) / 2;
            int x = 1, temp = mid;
            for(int i = 0; i < weights.size(); i++){
                if(weights[i] > temp){
                    x++;
                    temp = mid;
                }
                temp -= weights[i];
            }
            if(x > days){
                l = mid + 1;
            }
            else{
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
};