class Solution {
public:
    int rec(vector<int>&prices , bool flag , int idx , vector<vector<int>> &dp){ 
        if(idx == prices.size()){
            return 0;
        }
        if(dp[idx][flag] != -1) return dp[idx][flag];
        int profit = 0;
        if(flag == 0){
            profit = max(rec(prices , 1 , idx + 1 , dp ) - prices[idx] , rec(prices , 0 , idx + 1 , dp));
        }else{
            profit = max(rec(prices , 0 , idx + 1 , dp) + prices[idx] , rec(prices , 1 , idx + 1 , dp));
        }
        return dp[idx][flag] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size() + 1, vector<int>(2 , 0));
        for(int idx = prices.size()  ; idx >= 0 ; idx--){
            for(int flag = 0 ; flag < 2 ; flag++){
                         if(idx == prices.size()){
                            dp[idx][flag] = 0;
                            continue;
                        }
                        int profit = 0;
                        if(flag == 0){
                            profit = max(dp[idx + 1][1] - prices[idx] ,dp[idx + 1][0]);
                        }else{
                            profit = max(dp[idx + 1][0] + prices[idx] , dp[idx + 1][1]);
                        }
                        dp[idx][flag] = profit;
            }
        }
        return dp[0][0];
    }
};