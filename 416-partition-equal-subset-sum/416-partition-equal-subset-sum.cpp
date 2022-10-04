class Solution {
public:
     bool targetSumSubset(vector<int>&nums, int idx , int target , vector<vector<int>> &dp){
        if(target == 0) return true;
        else if(idx >= nums.size() || target < 0){
            return false;
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];
        bool include = false;
        if(nums[idx] <= target){
            include = targetSumSubset(nums , idx + 1 , target - nums[idx] , dp);
        }
        bool exclude = targetSumSubset(nums , idx + 1 , target ,dp);
        return dp[idx][target] = include | exclude;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int val : nums){
            sum += val;
        }
        vector<vector<int>> dp(nums.size() + 1 , vector<int>(sum/2 + 1 , -1));
        if(sum & 1) return false; // odd
        return targetSumSubset(nums , 0 , sum/2 ,dp);
    }
};