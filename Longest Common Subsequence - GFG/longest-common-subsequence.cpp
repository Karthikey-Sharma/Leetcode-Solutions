// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string text1, string text2)
    {
        vector<vector<int>> dp(text1.size() + 1 , vector<int>(text2.size() + 1 , 0));
        for(int i = dp.size() - 2 ; i >= 0 ; i--){
            for(int j = dp[i].size() - 2 ; j >= 0 ; j--){
                char ch1 = text1[i];
                char ch2 = text2[j];
                if(ch1 == ch2){
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }else{
                    dp[i][j] = max(dp[i][j + 1] , dp[i + 1][j]);
                }
            }
        }
        return dp[0][0];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends