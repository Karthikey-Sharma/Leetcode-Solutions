//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        stack<int> stack;
        vector<int> ans(n) ;
        for(int i = 0 ; i < n ; i++){
            while(!stack.empty() && a[stack.top()] >= a[i]){
                stack.pop();
            }
            if(stack.size() > 0){
                ans[i] = a[stack.top()];
            }else{
                ans[i] = -1;
            }
            stack.push(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends