//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
    vector<int> arranged(int arr[],int n)
    {
        vector<int> a(n);
        int negativeidx = 1;;
        int positiveidx = 0;
        for(int i = 0 ; i < n  ; i++){
            if(arr[i] < 0){
                a[negativeidx] = arr[i];
                negativeidx+= 2;
            }else{
                a[positiveidx] = arr[i];
                positiveidx+= 2;
            }
        }
         return a;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    vector<int> ans;
    Solution obj;
    ans=obj.arranged(a,n);
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    }
}

// } Driver Code Ends