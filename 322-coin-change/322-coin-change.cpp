class Solution {
public:
    int rec(int idx , vector<int>&coins , int amount , vector<vector<int>> &dp){
        if(idx == 0){
            if(amount % coins[idx] == 0) return amount / coins[idx];
            else return 1e9;
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        int take = INT_MAX;
        if(coins[idx] <= amount){
            take = 1 + rec(idx , coins , amount - coins[idx] ,dp);
        }
        int notTake = 0 + rec(idx - 1 , coins , amount ,dp );
        return dp[idx][amount] = min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() , vector<int>(amount + 1 , 0));
        for(int amt = 0 ; amt <= amount ; amt++){
             if(amt % coins[0] == 0) dp[0][amt] = amt / coins[0];
             else dp[0][amt] = 1e9;
        }
        for(int idx = 1 ; idx < coins.size() ; idx++){
            for(int amt = 0 ; amt <= amount ; amt++){
                int take = INT_MAX;
                if(coins[idx] <= amt){
                    take = 1 + dp[idx][amt - coins[idx]];
                }
                int notTake = 0 + dp[idx - 1][amt];
                dp[idx][amt] = min(take , notTake);
            }
        }
        int ans = dp[coins.size() - 1][amount];
        if(ans >= 1e9) return -1;
        else return ans;
    }
};