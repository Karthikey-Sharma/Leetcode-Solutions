/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findPeak(MountainArray & mountainArr){
        int left = 0;
        int right = mountainArr.length() - 1;
        int mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if((mid == mountainArr.length() - 1 || mountainArr.get(mid) > mountainArr.get(mid + 1)) && (mid == 0 || mountainArr.get(mid) > mountainArr.get(mid - 1))){
                return mid;
            }
            else if(mountainArr.get(mid + 1) > mountainArr.get(mid))
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return mid;
    }
    int binarySearch(MountainArray & mountainArr , int target , int peak){
        int left = 0 ; 
        int right = peak;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) > target){
                right = mid - 1;
            }else if(mountainArr.get(mid) < target){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
    int reverseBinarySearch(MountainArray & mountainArr , int target , int peak){
        int left = peak ;
        int right = mountainArr.length() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) > target){
                left = mid + 1;
            }else if(mountainArr.get(mid) < target){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        return -1;
        
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        if(target > mountainArr.get(peak)) return -1;
        int leftAns = binarySearch(mountainArr , target , peak);
        if(leftAns != -1) return leftAns;
        int rightAns = reverseBinarySearch(mountainArr , target , peak);
        return rightAns;
        

        
    }
};