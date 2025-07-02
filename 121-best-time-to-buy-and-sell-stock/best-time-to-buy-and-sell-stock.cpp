class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0], profit = 0;
        for(int j = 1; j < prices.size(); j++){
            profit = max(profit, prices[j] - minPrice);
            minPrice = min(minPrice, prices[j]);
        }
        return profit;
    }
};