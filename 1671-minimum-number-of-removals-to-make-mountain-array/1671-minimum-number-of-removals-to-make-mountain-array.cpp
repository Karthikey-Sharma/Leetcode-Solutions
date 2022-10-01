class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis(nums.size() , 0);
        lis[0] = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            int maxim = 0;
            for(int j = i - 1 ; j >= 0  ; j--){
                if(nums[i] > nums[j]){
                    maxim = max(lis[j] , maxim);
                }
            }
            lis[i] = maxim + 1;
        }
        
        vector<int> lds(nums.size() , 0);
        lds[nums.size() - 1] = 1;
        for(int i = nums.size() - 2 ; i >= 0 ; i--){
            int maxim = 0;
            for(int j = i + 1 ; j < nums.size() ; j++){
                if(nums[i] > nums[j]){
                    maxim = max(lds[j] , maxim);
                }
            }
            lds[i] = maxim + 1;
        }
        
        int largestSum = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            if(lds[i] == 1 || lis[i] == 1) continue;// mountain array ka condition vioalate ho jayega warna
            largestSum = max(largestSum , (lds[i] + lis[i] - 1));
        }
        return nums.size() - largestSum;
        
    }
};