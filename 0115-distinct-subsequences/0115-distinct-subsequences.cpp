class Solution {
public:
    
    int numDistinct(string s, string t) {
        // shifting 1 index to handle negative base case for tabulation
        vector<vector<double>> dp(s.size() + 1 , vector<double>(t.size() + 1 , 0));
        for(int i = 0 ; i <= s.size() ; i++){
            for(int j = 0 ; j <= t.size() ; j++){
                if(j == 0){
                    dp[i][j] =  1;
                    continue;
                }
                if(i == 0){
                    dp[i][j] =  0;
                    continue;
                } 
                
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else dp[i][j] =  dp[i - 1][j];
            }
        }
        return (int)dp[s.size()][t.size()];
    }
};