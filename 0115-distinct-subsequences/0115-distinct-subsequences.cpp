class Solution {
public:
    int rec(string &s , string &t , int i , int j , vector<vector<int>> &dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1]){
            return dp[i][j] = rec(s , t , i - 1 , j - 1 , dp) + rec(s , t , i - 1 , j , dp);
        }
        else return dp[i][j] = rec(s , t , i - 1 , j , dp);
    }
    int numDistinct(string s, string t) {
        // shifting 1 index to handle negative base case for tabulation
        vector<vector<int>> dp(s.size() + 1 , vector<int>(t.size() + 1 , -1));
        return rec(s , t , s.size()  , t.size() , dp);
    }
};