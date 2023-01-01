//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int N, string S){
        string operands = "";
        string operators = "";
        for(int i = 0 ; i < S.size() ; i++){
            if(i % 2 == 0) operands += S[i];
            else operators += S[i];
        }
        vector<vector<int>> dpt(operands.size() , vector<int>(operands.size())) ;
        vector<vector<int>> dpf(operands.size() , vector<int>(operands.size()));
        for(int gap = 0 ; gap < operands.size() ; gap++){
            for(int i = 0 , j = gap ; j < operands.size() ; i++ , j++){
                if(gap == 0){
                    char ch = operands[i];
                    if(ch == 'T'){
                        dpt[i][j] = 1;
                        dpf[i][j] = 0;
                    }else{
                        dpt[i][j] = 0;
                        dpf[i][j] = 1;
                    }
                }else{
                    for(int k = i ; k < j ; k++){
                        char oprtr = operators[k];
                        int ltc = dpt[i][k];
                        int rtc = dpt[k + 1][j];
                        int lfc = dpf[i][k];
                        int rfc = dpf[k + 1][j];
                        if(oprtr == '&'){
                            dpt[i][j] =  (dpt[i][j]  % 1003 )+ (ltc * rtc) % 1003;
                            dpf[i][j] = (dpf[i][j]  % 1003)  + (lfc * rtc + ltc * rfc + lfc * rfc) % 1003;
                        }else if(oprtr == '|'){
                            dpt[i][j] = (dpt[i][j]  % 1003)+ (ltc * rtc + lfc * rtc + ltc * rfc) % 1003;
                            dpf[i][j] = (dpf[i][j]  % 1003)  + (lfc * rfc)  % 1003;
                        }else{ // ^ (xor)
                            dpt[i][j] = dpt[i][j] + (ltc * rfc + lfc * rtc) % 1003;
                            dpf[i][j] = dpf[i][j] + (lfc * rfc + ltc * rtc) % 1003;
                        }
                    }
                }
            }
            
        }
        return dpt[0][operands.size() - 1] % 1003;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends