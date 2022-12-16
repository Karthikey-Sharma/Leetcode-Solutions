//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N - 1 , vector<int>(N - 1));
        for(int gap = 0 ; gap < N ; gap++){
            for(int i = 0 , j = gap ; j < dp.size() ; i++ , j++){
                if(gap == 0){
                    dp[i][j] = 0;
                }else if(gap == 1){
                    dp[i][j] = arr[i] * arr[j] * arr[j + 1];
                }else{
                    int minimum = INT_MAX;
                    for(int k = i ; k < j ; k++){
                        int leftCost = dp[i][k];
                        int rightCost = dp[k + 1][j];
                        int multiplicationCost = arr[i] * arr[k + 1] * arr[j + 1];
                        
                        if((leftCost + rightCost + multiplicationCost) < minimum){
                            minimum = leftCost + rightCost + multiplicationCost;
                        }
                    }
                    dp[i][j] = minimum;
                }
            }
        }
        return dp[0][dp.size() - 1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends