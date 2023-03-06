//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int lo = 1;
	    int hi = m;
	    while(lo <= hi){
	        int mid = lo + (hi - lo) / 2;
	        if(pow(mid , n) < m){
	            lo = mid + 1;
	        }else if(pow(mid , n) > m){
	            hi = mid - 1;
	        }else{
	            return mid;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends