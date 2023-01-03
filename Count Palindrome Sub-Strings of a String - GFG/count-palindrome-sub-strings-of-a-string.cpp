//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}


// } Driver Code Ends


int CountPS(char s[], int N)
{
    vector<vector<bool>> dp( N , vector<bool>(N));
        int count = 0;
        for(int gap = 0 ; gap < N ; gap++){
            for(int i = 0 , j = gap ; j < dp.size() ; i++ , j++){
                if(gap == 0){
                    dp[i][j] = true;
                }else if(gap == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }else {
                    if((s[i] == s[j]) && (dp[i + 1][j - 1] == true)){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = false;
                    }
                }
                if(dp[i][j] == true && gap != 0){
                    count++;
                }
            }
        }
        return count;
    
}