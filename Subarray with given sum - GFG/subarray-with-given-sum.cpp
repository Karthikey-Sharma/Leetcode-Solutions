//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        if(s == 0) return {-1};
        bool found = false;
        long long sum = 0;
        vector<int> ans;
        int left=-1;
        int right = 0;
        while(right < n){
            sum += arr[right];
            //cout << sum << endl;
            if(sum > s){
                while(sum > s){
                    left++;
                    sum -= arr[left];
                    //cout << "remSum " << sum << endl;
                }
                
            }
            if(sum == s){
                ans.push_back(left + 2);
                ans.push_back(right + 1);
                return ans;
            }
            right++;
        }
        ans.push_back(-1);
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
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends