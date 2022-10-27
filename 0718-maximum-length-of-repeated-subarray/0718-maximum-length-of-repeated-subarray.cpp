class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // same as longest common substring
        vector<vector<int>>dp(nums1.size() + 1 , vector<int>(nums2.size() + 1 , 0));
        int maxim = 0;
        for(int i = 1 ; i < dp.size() ; i++){
            for(int j = 1 ; j < dp[i].size() ; j++){
                int num1 = nums1[i - 1];
                int num2 = nums2[j - 1];
                if(num1 != num2){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                
                maxim = max(maxim , dp[i][j]);
            }
        }
        return maxim;
    }
};