//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int rec(string A , string B , int i , int j , vector<vector<int>>&dp){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(A[i - 1] == B[j - 1]) return dp[i][j] = 1 + rec(A , B , i - 1 , j - 1 ,dp);
        else return dp[i][j] = max(rec(A , B , i - 1 , j , dp) , rec(A , B , i , j - 1 , dp));
    }
    int lcs(string A , string B){
        vector<vector<int>> dp(A.size() + 1 , vector<int>(B.size() + 1 , -1));
        return rec(A , B, A.size()  , B.size() , dp);
    }
    int longestPalinSubseq(string A) {
        string B = A;
        reverse(B.begin(), B.end());
        return lcs(A , B);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends