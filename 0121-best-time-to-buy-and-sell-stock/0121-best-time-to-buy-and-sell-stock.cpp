class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX;
        int maxProfit = 0;
        for(int i = 0 ; i < prices.size() ; i++){
            if(prices[i] < lsf){
                lsf = prices[i];
            }
            int profit = (prices[i] - lsf);
            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};