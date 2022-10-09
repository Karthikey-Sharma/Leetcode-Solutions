class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1 , 0);
        for(int amt = 0 ; amt <= amount ; amt++){
             if(amt % coins[0] == 0) prev[amt] = amt / coins[0];
             else prev[amt] = 1e9;
        }
        for(int idx = 1 ; idx < coins.size() ; idx++){
            for(int amt = 0 ; amt <= amount ; amt++){
                int take = INT_MAX;
                if(coins[idx] <= amt){
                    take = 1 + curr[amt - coins[idx]];
                }
                int notTake = 0 + prev[amt];
                curr[amt] = min(take , notTake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        else return ans;
    }
};