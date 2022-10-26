class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        // Space Optimixation o(m)
        int n = s.size();
        int m = t.size();
        vector<int> prev(m + 1 , 0);
        vector<int> curr(m + 1, 0);
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= m ; j++){
                if(i == 0 || j == 0){
                    prev[j] = 0 ;
                    continue;
                }
                if(s[i - 1] == t[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};