class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = x;
        int res = x;
        while(left <= right){
            long long mid = (left + right) / 2;
            if(mid * mid == x){
                return mid;
            }
            if(mid * mid < x){
                res = mid;
                left = mid + 1; 
            }
            else{
                right = mid - 1;
            }
        } 
        return res;
    }
};