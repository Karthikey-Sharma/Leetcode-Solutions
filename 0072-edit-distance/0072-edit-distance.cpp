class Solution {
public:
    int minDistance(string word1, string word2) {
        // doing index shifting for tabulation
        // Now Tabulation
        vector<int> prev(word2.size() + 1 , 0);
        vector<int> curr(word2.size() + 1 , 0);
        for(int j = 0 ; j <= word2.size() ; j++) prev[j] = j;
        for(int i = 1 ; i <= word1.size() ; i++){
                curr[0] = i;
            for(int j = 1 ; j <= word2.size() ; j++){
                if(word1[i - 1] == word2[j - 1]){
                    curr[j] =  prev[j - 1]; 
                }else{
                    curr[j] = min(1 + prev[j - 1] , min(1 + prev[j], 1 + curr[j - 1]));
                }
            }
            prev = curr;
        }
        return prev[word2.size()];
    }
};