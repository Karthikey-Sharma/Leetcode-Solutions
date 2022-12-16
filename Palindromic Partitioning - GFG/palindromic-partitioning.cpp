//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string s)
    {
        vector<vector<bool>> dp(s.size() , vector<bool>(s.size()));
        for(int gap = 0 ; gap < s.size() ; gap++){
            for(int i = 0 , j = gap ; j < s.size() ; i++ , j++){
                if(gap == 0){
                    dp[i][j] = true;
                }else if(gap == 1){
                    dp[i][j] = (s[i] == s[j]);
                }else{
                    if(s[i] == s[j] && dp[i + 1][j - 1] == true){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        
        vector<int> storage(s.size());
        storage[0] = 0;
        for(int j = 1 ; j < s.size() ; j++){
            if(dp[0][j] == true){
                storage[j] = 0;
            }else{
                int minimum = INT_MAX;
                for(int i = j ; i >= 1 ; i--){
                    if(dp[i][j] == true){
                        if(storage[i - 1] < minimum){
                            minimum = storage[i - 1];
                        }
                    }
                }
                storage[j] = minimum + 1;
            }
        }
        return storage[s.size() - 1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends