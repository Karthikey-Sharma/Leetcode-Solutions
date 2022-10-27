//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int longestCommonSubsequence(string text1, string text2) {
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
	int minOperations(string str1, string str2) 
	{ 
	    return str1.size() + str2.size() - 2 * longestCommonSubsequence(str1 , str2);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends