class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if((mid == nums.size() - 1 || nums[mid] > nums[mid + 1]) && (mid == 0 || nums[mid] > nums[mid - 1])){
                return mid;
            }
            else if(nums[mid + 1] > nums[mid])
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return mid;
    }
};