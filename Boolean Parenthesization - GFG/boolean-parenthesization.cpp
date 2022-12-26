//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int N, string S){
        string str1 = "";
        string str2 = "";
        
        for(int i = 0 ; i < S.size() ; i++){
            if(i % 2 == 0) str1 += S[i];
            else str2 += S[i];
        }
        
        int n = str1.size();
        vector<vector<int>>t(n , vector<int>(n , 0));
        vector<vector<int>> f(n , vector<int>(n , 0));
        for (int gap = 0; gap < n; gap++) {
          int si = 0, ei = gap;
          while (ei < n) {
            if (gap == 0) {
              t[si][ei] = str1.at(si) == 'T' ? 1 : 0;
              f[si][ei] = str1.at(si) == 'F' ? 1 : 0;
            } else {
              for (int cp = si; cp < ei; cp++) {
                char sign = str2.at(cp);
                if (sign == '&') {
                  t[si][ei] += ((t[si][cp] % 1003) *( t[cp + 1][ei] % 1003)) % 1003;
                  f[si][ei] += (((t[si][cp] % 1003 ) % 1003* (f[cp + 1][ei] % 1003) % 1003) % 1003+ ((f[si][cp]% 1003 )* t[cp + 1][ei] % 1003) % 1003
                                + ((f[si][cp]% 1003) * (f[cp + 1][ei])% 1003))% 1003;
                }
                if (sign == '|') {
                  t[si][ei] += (((t[si][cp]% 1003) * (t[cp + 1][ei]% 1003))% 1003 + ((t[si][cp]% 1003) * (f[cp + 1][ei]% 1003))% 1003
                                + (f[si][cp] * t[cp + 1][ei]))% 1003;
                  f[si][ei] += ((f[si][cp]) * (f[cp + 1][ei]))% 1003;
                }
                if (sign == '^') {
                  t[si][ei] += ((t[si][cp] * f[cp + 1][ei])% 1003 + (f[si][cp] * t[cp + 1][ei])% 1003)% 1003;
                  f[si][ei] += ((t[si][cp] * t[cp + 1][ei])% 1003 + (f[si][cp] * f[cp + 1][ei])% 1003)% 1003;
                }
              }
            }
            si++;
            ei++;
          }
        }
        return (t[0][t[0].size() - 1])% 1003;
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