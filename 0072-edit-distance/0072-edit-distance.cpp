class Solution {
public:
    int rec(string &word1 , string &word2 , int i , int j , vector<vector<int>>& dp){
        if(j < 0) return i + 1;
        if(i < 0) return j + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]){
            return dp[i][j] = 0 + rec(word1 , word2 , i - 1 , j - 1 ,dp);
        }else{
            return dp[i][j] = min(1 + rec(word1 , word2 , i , j - 1 , dp) , min(1 + rec(word1 , word2 , i - 1 , j ,dp) ,1 + rec(word1 , word2 , i - 1 , j - 1 , dp)));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() , vector<int>(word2.size() , -1));
        return rec(word1 , word2 , word1.size() - 1 , word2.size() - 1 , dp);
    }
};