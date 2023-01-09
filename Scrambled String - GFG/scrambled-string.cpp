//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    int dp[31][31][31];
    bool isScrambleRec(string s1 , string s2 , int si1  , int si2 , int len){

        if(s1.substr(si1 , len) == s2.substr(si2 , len)) return true;
        if(dp[si1][si2][len] != -1) return dp[si1][si2][len] ;
        for(int k = 1 ; k < len ; k++){
            if((isScrambleRec(s1 , s2 , si1 , si2 , k) && isScrambleRec(s1 , s2 , si1 + k , si2 +  k , len - k)) || (isScrambleRec(s1 , s2 , si1 , si2 + len - k , k) && isScrambleRec(s1 , s2 , si1 + k , si2 , len - k))){
                return dp[si1][si2][len] = true;
            }
        }

        return dp[si1][si2][len] = false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        for(int i = 0 ; i < 31 ; i++){
            for(int j = 0 ; j < 31 ; j++){
                for(int k = 0 ; k < 31 ; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
        return isScrambleRec(s1 , s2 , 0 , 0 , s1.size());
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends