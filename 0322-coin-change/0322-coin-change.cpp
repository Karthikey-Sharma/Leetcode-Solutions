class Solution {
public:
    int rec(vector<int>&coins , int amount , int idx , vector<vector<int>>&dp){
        if(idx == 0) {
            if((amount % coins[idx]) == 0){
                return (amount / coins[idx]);
            }
            else return INT_MAX / 2;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int take = INT_MAX /2;
        if(amount >= coins[idx]){
            take = 1 + rec(coins , amount - coins[idx] , idx , dp);
        }
        int notTake = rec(coins , amount , idx - 1 , dp);
        return dp[idx][amount] =  min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+ 1 , vector<int>(amount + 1, -1));
        int ans =  rec(coins , amount , coins.size() - 1 , dp);
        if(ans == INT_MAX / 2) return -1;
        return ans;
        
    }
};