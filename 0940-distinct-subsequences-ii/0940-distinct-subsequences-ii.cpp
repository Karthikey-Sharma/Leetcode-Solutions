class Solution {
public:
    int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        vector<long long> dp(s.size() + 1);
        dp[0] = 1;
        map<char , int> lastOccurence;
        for(int i = 1 ; i <= s.size() ; i++){
            char ch = s[i - 1];
            dp[i] = ((2 % MOD) * (dp[i - 1] % MOD )) % MOD;
            
            if(lastOccurence.find(ch) != lastOccurence.end()){
                int lo = lastOccurence[ch];
                dp[i] = ((dp[i] % MOD )- (dp[lo - 1] % MOD)) % MOD;
            }
            
            lastOccurence[ch] = i ;
        }
       
        if(dp[s.size()] <= 0) dp[s.size()] += MOD;
        return ((dp[s.size()]) - 1) % MOD;
    }
};