//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends


class Solution{
public:
    int minOperations(int *arr,int n)
    {
        int steps = 0;
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0 ; i < n ; i++){
            if(!pq.empty() && pq.top() < arr[i]){
                steps += (arr[i] - pq.top());
                pq.push(arr[i]);
                pq.pop();
            }
            pq.push(arr[i]);
        }
        return steps;
    }
};

//{ Driver Code Starts.

int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int  a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution ob;
        cout<<ob.minOperations(a,n)<<endl;
    }
    
	return 0;
}
// } Driver Code Ends