class Solution {
public:
    int rec(vector<vector<int>> &piles , int idx , int k , vector<vector<int>>&dp){
        if(idx == piles.size() || k == 0){
            return 0;
        }
        if(dp[idx][k] != -1) return dp[idx][k];
        int notTake = rec(piles , idx + 1 , k , dp);
        int take = INT_MIN;
        int sum = 0;
        for(int i = 0 ; i < min((int)piles[idx].size() , k ) ; i++){
            sum += piles[idx][i];
            take = max(take , rec(piles , idx + 1 , k - (i + 1) , dp) + sum);
        }
        return dp[idx][k] = max(take , notTake);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size()  , vector<int>(k + 1 , -1));
        return  rec(piles , 0 , k ,dp);
    }
};