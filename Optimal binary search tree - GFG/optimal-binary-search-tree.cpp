//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        vector<int> psa(n);
        psa[0] = freq[0];
        for(int i = 1 ; i < n ; i++){
            psa[i] = psa[i - 1] + freq[i];
        }
        vector<vector<int>> dp(n , vector<int>(n , 0));
        for(int gap = 0 ; gap < n ; gap++){
            for(int i = 0 , j = gap ; j < dp.size() ; i++ , j++){
                if(gap == 0){
                    dp[i][j] = freq[i];
                }else if(gap == 1){
                    int f1 = freq[i];
                    int f2 = freq[j];
                    dp[i][j] = min(f1 + 2 * f2 , f2 + 2 * f1);
                }else{
                    int minim = INT_MAX;
                    int fs = psa[j] - ( i == 0 ? 0 : psa[i - 1]);
                    for(int k = i ; k <= j ; k++){
                        int leftVal = (k == i ? 0 :  dp[i][k - 1]);
                        int rightVal = (k == j ? 0 :  dp[k + 1][j]);
                        
                        if(leftVal + rightVal + fs < minim){
                            minim = leftVal + rightVal + fs;
                        }
                    }
                    
                    dp[i][j] = minim;
                }
            }
        }
        return dp[0][n - 1];
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
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends