class Solution {
public:
    int minDistance(string word1, string word2) {
        // doing index shifting for tabulation
        // Now Tabulation
        vector<vector<int>> dp(word1.size() + 1 , vector<int>(word2.size() + 1 , 0));
        for(int i = 0 ; i < dp.size() ; i++){
            for(int j = 0 ; j < dp[i].size() ; j++){
                if(j == 0){
                    dp[i][j] = i ;
                    continue;
                }
                if(i == 0){
                    dp[i][j] = j ;
                    continue;
                }
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = 0 + dp[i - 1][j - 1]; 
                }else{
                    dp[i][j] = min(1 + dp[i][j - 1] , min(1 + dp[i - 1][j], 1 + dp[i - 1][j - 1]));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};