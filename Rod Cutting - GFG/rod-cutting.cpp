//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> prev(n + 1 , 0);
        vector<int> curr(n + 1, 0);
        for(int i = 0 ; i <= n; i++){
            prev[i] = i * price[0];
        }
        for(int i = 1 ; i < n ;i++){
            for(int j = 0 ; j <= n ; j++){
              int take = INT_MIN;
              int rodLength = i + 1;
              if(rodLength <= j){
                  take = curr[j-rodLength]+ price[i];
              }
              int notTake = prev[j];
              curr[j] = max(take , notTake);
            }
            prev = curr;
        }
       return prev[n];
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