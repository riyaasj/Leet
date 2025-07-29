class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m * k > n) return -1;
        int l = bloomDay[0], r = bloomDay[0];
        for(int i: bloomDay){
            l = min(l, i);
            r = max(r, i);
        }
        int res;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int bouquets = 0, count = 0;
            for(int i: bloomDay){
                if(i <= mid){
                    count++;
                }
                else{
                    bouquets += count / k;
                    count = 0;
                }
            }
            bouquets += count / k;
            if(bouquets >= m){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return res;
    }
};