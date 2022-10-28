class Solution {
public:
    int rec(string &word1 , string &word2 , int i , int j , vector<vector<int>>& dp){
        if(j == 0) return i ;
        if(i == 0) return j ;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i - 1] == word2[j - 1]){
            return dp[i][j] = 0 + rec(word1 , word2 , i - 1 , j - 1 ,dp);
        }else{
            return dp[i][j] = min(1 + rec(word1 , word2 , i , j - 1 , dp) , min(1 + rec(word1 , word2 , i - 1 , j ,dp) ,1 + rec(word1 , word2 , i - 1 , j - 1 , dp)));
        }
    }
    int minDistance(string word1, string word2) {
        // doing index shifting for tabulation
        vector<vector<int>> dp(word1.size() + 1 , vector<int>(word2.size() + 1 , -1));
        return rec(word1 , word2 , word1.size() , word2.size() , dp);
    }
};