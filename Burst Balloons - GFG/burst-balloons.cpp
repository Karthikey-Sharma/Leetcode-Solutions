//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int N, vector<int> &arr) {
        vector<vector<int>> dp(arr.size() , vector<int>(arr.size()));
        for(int gap = 0 ; gap < arr.size() ; gap++){
            for(int i = 0 , j = gap ; j < dp.size() ; i++ , j++){
                int maxim = INT_MIN;
                for(int k = i ; k <= j ; k++){
                    int left = (k == i ? 0 : dp[i][k - 1]);
                    int right = (k == j ? 0 : dp[k + 1][j]);
                    int val = (i == 0 ? 1 : arr[i - 1]) * arr[k] * (j == N - 1 ? 1 : arr[j + 1]);
                    
                    int total = left + right + val;
                    if(total > maxim){
                        maxim = total;
                    }
                }
                dp[i][j] = maxim;
            }
        }
        return dp[0][arr.size() - 1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends