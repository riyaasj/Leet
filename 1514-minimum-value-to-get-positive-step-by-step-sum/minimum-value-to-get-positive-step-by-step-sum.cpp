class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int m = 0, sum = 0;
        for(int i: nums){
            sum += i;
            m = min(m, sum); 
        }
        return (m * -1) + 1;
    }
};