//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));
        int maxim = 0;
        for(int i = 1 ; i < dp.size() ; i++){
            for(int j = 1 ; j < dp[i].size() ; j++){
                char ch1 = S1[i - 1];
                char ch2 = S2[j - 1];
                if(ch1 != ch2){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                
                if(dp[i][j] > maxim){
                    maxim = dp[i][j];
                }
                
            }
        }
        return maxim;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends