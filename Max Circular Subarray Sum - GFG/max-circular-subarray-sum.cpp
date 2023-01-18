//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadaneMin(int *  nums , int n){
        int csum = nums[0];
        int osum = nums[0];

        for(int i = 1 ; i < n ; i++){
            if(csum < 0){
                csum += nums[i];
            }else{
                csum = nums[i];
            }

            if(osum > csum){
               osum = csum;
            }
        }
        return osum;
    }

    int kadaneMax(int * nums , int n){
        int csum = nums[0];
        int osum = nums[0];

        for(int i = 1 ; i < n ; i++){
            if(csum >= 0){
                csum += nums[i];
            }else{
                csum = nums[i];
            }

            if(osum < csum){
                osum = csum;
            }
        }
        return osum;
    }
    int circularSubarraySum(int nums[], int num){
        
        int sum = 0;
        for(int i = 0 ; i < num ; i++){
            sum += nums[i];
        }
        int maxSum = kadaneMax(nums , num);

        int minSum =  kadaneMin(nums , num);
        int circularMax = sum - minSum;

        if(maxSum > 0) return max(maxSum , circularMax);
        return maxSum;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends