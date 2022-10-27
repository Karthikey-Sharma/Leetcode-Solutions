//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int longestPalindromeSubseq(string s) {
        // Pepcoding Solution's
        vector<vector<int>> dp(s.size() , vector<int>(s.size() , 0));
        for(int gap = 0 ; gap < s.size() ; gap++){
            for(int i = 0 , j = gap ; j < dp.size() ; i++ , j++){
                if(gap == 0){
                    dp[i][j] = 1;
                }else if(gap == 1){
                    dp[i][j] = (s[i] == s[j]) ? 2 : 1;
                }else{
                    if(s[i] == s[j]){
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    }else{
                        dp[i][j] = max(dp[i + 1][j] , dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[0][s.size() - 1];
    }
    int findMinInsertions(string S){
        return S.size() - longestPalindromeSubseq(S);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends