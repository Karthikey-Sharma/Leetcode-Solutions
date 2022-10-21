//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int rec(int price[] , int n , int idx , vector<vector<int>>&dp){
      if(idx == 0){
          return n * price[idx];
      }
      if(dp[idx][n] != -1) return dp[idx][n];
      int take = INT_MIN;
      int rodLength = idx + 1;
      if(rodLength <= n){
          take = rec(price , n - rodLength, idx , dp) + price[idx];
      }
      int notTake = rec(price , n , idx - 1 , dp);
      return dp[idx][n] = max(take , notTake);
  }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1 , vector<int>(n + 1 , -1));
        return rec(price , n , n - 1 ,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends