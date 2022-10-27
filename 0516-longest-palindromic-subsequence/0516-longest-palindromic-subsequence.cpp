class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1 = s;
        reverse(s.begin() , s.end());
        string text2 = s;
        vector<vector<int>> dp(text1.size() + 1 , vector<int>(text2.size() + 1 , 0));
        for(int i = dp.size() - 2 ; i >= 0 ; i--){
            for(int j = dp[i].size() - 2 ; j >= 0 ; j--){
                char ch1 = text1[i];
                char ch2 = text2[j];
                if(ch1 == ch2){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }else{
                    dp[i][j] = max(dp[i][j + 1] , dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
};