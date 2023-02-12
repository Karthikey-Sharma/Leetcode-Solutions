//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	   unordered_map<int , int> map;
	   int curr_sum = 0;
	   int max_length = 0;
	   map[0] = -1;
	   for(int i = 0 ; i < n ; i++){
	       curr_sum += arr[i];
	       int rem = curr_sum % k;
	       if(rem < 0) {
	           rem += k;
	       }
	       if(map.find(rem) == map.end()){
	           map[rem] = i;
	       }else{
	           int len = i - map[rem];
	           if(len > max_length){
	               max_length = len;
	           }
	       }
	   }
	   return max_length;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends