class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int m = INT_MAX, sum = 0;
        for(int i: nums){
            sum += i;
            m = min(m, sum); 
        }
        if(m >= 0){
            return 1;
        }
        return (m * -1) + 1;
    }
};