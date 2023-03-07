//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   bool isPossible(int *  nums , int n, int  mid , int k){
        int partitions = 1;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            if(sum > mid){
                partitions++;
                sum = nums[i];
            }
        }
        return partitions <= k;
    }
    int splitArray(int nums[] ,int n, int k) {
        int sum = 0;
        int maxim = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            maxim = max(maxim , nums[i]);
        }

        int lo = maxim;
        int hi = sum;
        int ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(isPossible(nums , n,  mid , k)){
                hi = mid - 1;
                ans = mid;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends