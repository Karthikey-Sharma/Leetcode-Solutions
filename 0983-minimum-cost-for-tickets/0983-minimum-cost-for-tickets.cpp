class Solution {
public:
    int rec(vector<int>&days , vector<int>&costs , int idx , vector<int>&dp){
        if(idx >= days.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int option1 = costs[0] + rec(days , costs , idx + 1 ,dp);
        int i;
        for(i = idx ; i < days.size() && days[i] < days[idx] + 7 ; i++);
        int option2 = costs[1] + rec(days , costs , i ,dp) ;
        
        for(i = idx ; i < days.size() && days[i] < days[idx] + 30 ; i++);
        int option3 = costs[2] + rec(days , costs , i ,dp) ;
        
        return dp[idx] = min({option1 , option2 , option3});
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(366 , -1);
        return rec(days , costs , 0 ,  dp);
    }
};