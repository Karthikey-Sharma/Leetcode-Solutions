//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long dp[1005][1005];
    long long rec(int * arr , int n , int i , int j){
        if(i > j) return 0;
        if(i >= n) return 0;
        if(j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        long long selectFirstElement = arr[i] + min(rec(arr , n , i + 2 , j) , rec(arr , n , i + 1 , j - 1));
        long long selectLastElement =  arr[j] + min(rec(arr , n , i + 1 , j - 1) , rec(arr , n , i , j - 2));
        return dp[i][j] = max(selectFirstElement , selectLastElement);
    }
    long long maximumAmount(int arr[], int n){
        for(int i = 0 ; i < 1005 ; i++){
            for(int j = 0 ; j < 1005 ; j++){
                dp[i][j] = -1;
            }
        }
        return rec(arr , n , 0 , n - 1);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends