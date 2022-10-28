//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
    int MOD = 1e9 + 7;
    int distinctSubsequences(string s) {
        vector<long long> dp(s.size() + 1);
        dp[0] = 1;
        map<char , int> lastOccurence;
        for(int i = 1 ; i <= s.size() ; i++){
            char ch = s[i - 1];
            dp[i] = ((2 % MOD) * (dp[i - 1] % MOD )) % MOD;
            
            if(lastOccurence.find(ch) != lastOccurence.end()){
                int lo = lastOccurence[ch];
                dp[i] = ((dp[i] % MOD )- (dp[lo - 1] % MOD)) % MOD;
            }
            
            lastOccurence[ch] = i ;
        }
       
        if(dp[s.size()] <= 0) dp[s.size()] += MOD;
        return ((dp[s.size()])) % MOD;
    }
	
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends