//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends
class Solution{
public:
    int onesComplement(int n){
        if(n == 0) return 1;
        int mask = 0;
        int m = n;
        while(n != 0){
            mask = (mask << 1) | 1;
            n = n >> 1;
        }
        int ans= (~m) & mask;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        Solution ob;
        cout<<ob.onesComplement(n)<<"\n";
    }
}
// } Driver Code Ends