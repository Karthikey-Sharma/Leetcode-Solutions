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
        vector<vector<int>>dp(prices.size() , vector<int>(2 , -1));
        return rec(prices , 0 , 0 , dp);
    }
};