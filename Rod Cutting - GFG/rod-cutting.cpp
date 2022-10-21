//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1 , vector<int>(n + 1 , 0));
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j <= n ; j++){
                if(i == 0){
                  dp[i][j] = j * price[i];
                  continue;
             }
              int take = INT_MIN;
              int rodLength = i + 1;
              if(rodLength <= j){
                  take = dp[i][j-rodLength]+ price[i];
              }
              int notTake = dp[i - 1][j];
              dp[i][j] = max(take , notTake);
            }
        }
        return dp[n - 1][n];
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