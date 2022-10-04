class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int val : nums) sum += val;
        if(sum & 1) return false;
        int target = sum / 2 ;
        vector<vector<bool>> dp(nums.size() + 1 , vector<bool>(target + 1 , false));
        for(int i = 0 ; i < dp.size() ; i++){
            for(int j = 0 ; j <= target ; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }else if(i == 0){
                    dp[i][j] = false;
                }else{
                   if(dp[i - 1][j] == true){
                       dp[i][j] = true;
                   }else{
                       int val = nums[i - 1];
                       if(j >= val){
                           if(dp[i - 1][j - val] == true){
                               dp[i][j] = true;
                           }
                       }
                   }
                }
            }
        }
        return dp[nums.size()][target];
    }
};