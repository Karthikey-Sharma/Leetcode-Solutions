//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        int lo = 0;
        int hi = n - 1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(v[mid] < x){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        
        if(v[lo] == x) return lo;
        else if(v[lo] > x){
            if(lo - 1 >= 0) return lo - 1;
            else return -1;
        }else{
            return lo;
        }
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends