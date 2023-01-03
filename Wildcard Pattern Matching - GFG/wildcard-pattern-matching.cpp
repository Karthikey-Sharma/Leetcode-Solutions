//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool rec(string s, string p , int i , int j , vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0){
            for(int ii = 0 ; ii <= j ; ii++){
                if(p[ii] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(i >= 0 && j < 0){
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = rec(s , p , i - 1 , j - 1 , dp);
        else if(p[j] == '*'){
            return dp[i][j] = (rec(s , p , i , j - 1 , dp) || rec(s , p , i - 1 , j , dp));
        }
        else return dp[i][j] = false;
    }
    int wildCard(string pattern,string str)
    {
        vector<vector<int>> dp(str.size() , vector<int>(pattern.size() , -1)); 
        return  rec(str , pattern , str.size() - 1 , pattern.size() - 1 , dp);
        
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends