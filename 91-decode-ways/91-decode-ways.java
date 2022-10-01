class Solution {
    public int memo(String s ,int idx , int[] dp){
        if(idx == s.length()){
            return dp[idx] = 1;
        }
        if(dp[idx] != 0) return dp[idx];
        int ans = 0;
        if(s.charAt(idx) >= '1' && s.charAt(idx) <= '9'){
            ans += memo(s  , idx + 1 ,dp);
        }
        
        if(idx + 1 < s.length() && (s.charAt(idx) == '1' || s.charAt(idx) == '2' && s.charAt(idx + 1) <= '6')){
            ans += memo(s , idx + 2 ,dp );
        }
        return dp[idx] = ans;
    }
    
    public int numDecodings(String s) {
        int[] dp = new int[s.length() + 1];
        return memo(s , 0 ,dp);
    }
}