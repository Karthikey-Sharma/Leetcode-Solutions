class Solution {
public:
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