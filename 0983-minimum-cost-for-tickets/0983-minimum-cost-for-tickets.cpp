class Solution {
public:
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size() + 1 , 0);
        dp[days.size()] = 0;
        for(int idx = days.size() - 1 ; idx >= 0 ; idx--){
            int option1 = costs[0] + dp[idx + 1];
            int i;
            for(i = idx ; i < days.size() && days[i] < days[idx] + 7 ; i++);
            int option2 = costs[1] + dp[i];

            for(i = idx ; i < days.size() && days[i] < days[idx] + 30 ; i++);
            int option3 = costs[2] + dp[i];

            dp[idx] = min({option1 , option2 , option3});
        }
        return dp[0];
    }
};