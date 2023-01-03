//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    #define ll long long
    ll MOD = 1e9 + 7;
    
    long long int  countPS(string str)
    {
        vector<vector<ll>> dp(str.size() , vector<ll>(str.size() , 0));
        for(int gap = 0 ; gap < str.size() ; gap++){
            for(int i = 0 , j = gap ; j < str.size() ; j++ , i++){
                if(gap == 0){
                    dp[i][j] = 1;
                }else if(gap == 1){
                    dp[i][j] = (str[i] == str[j] ? 3 : 2);
                }else{
                    if(str[i] == str[j]){
                        dp[i][j] = (1 + dp[i + 1][j] + dp[i][j - 1]) % MOD;
                    }else{
                        dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                    }
                }
            }
        }
        
        return dp[0][str.size() - 1] % MOD;
       
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends