//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1  , vector<int>(m + 1 , 0));
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j <= m ; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0 ;
                    continue;
                }
                if(s[i - 1] == t[j - 1])  dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
    int shortestCommonSupersequence(string s, string t, int n, int m)
    {
        return n + m - longestCommonSubsequence(s , t );
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends