class Solution {
public:
    int lcs(string &s , string &t , int i , int j  , vector<vector<int>>&dp){
        /// By Index Shifting
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1]) return dp[i][j] = 1 + lcs(s , t , i - 1, j - 1 , dp);
        else return dp[i][j] = max(lcs(s , t , i - 1 , j , dp) , lcs(s , t , i , j - 1 ,dp));
    }
    int longestCommonSubsequence(string S1, string S2) {
        int n = S1.size();
        int m = S2.size();
        vector<vector<int>> dp(n + 1  , vector<int>(m + 1 , -1));
        return lcs(S1 , S2 , n, m , dp);
    }
};