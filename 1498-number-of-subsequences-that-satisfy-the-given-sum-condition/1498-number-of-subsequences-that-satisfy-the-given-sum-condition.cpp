class Solution {
public:
    int MOD = 1e9 + 7;
    long long pow(int x , int y){
        if(x == 0) return 0;
        if(y == 1) return x;
        if(y == 0) return 1;
        long long ans = pow(x , y / 2);
        if(y % 2 == 0) return ((ans % MOD) * (ans % MOD)) % MOD;
        else return ((((ans % MOD) * (ans % MOD)) % MOD) * (x % MOD)) % MOD;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int i = 0 ;
        int j = nums.size() - 1;
        int ans = 0;
        while(i <= j){
            if((nums[i] + nums[j]) <= target){
                ans = ((ans % MOD) + (pow(2 , j - i)) % MOD) % MOD ;
                i++;
            }else{
                j--;
            }
        }
        return ans % MOD ;
    }
};