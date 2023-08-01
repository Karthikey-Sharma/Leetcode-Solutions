//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        priority_queue<int , vector<int> , greater<int>> pq;
        for(int i = 0 ; i <= k ; i++){
            pq.push(arr[i]);
        }
        vector<int> ans;
        if(k + 1 < n){
            for(int i = k + 1; i < n ; i++){
                int top = pq.top();
                pq.pop();
                
                ans.push_back(top);
                
                pq.push(arr[i]);
            }
        }
        
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends