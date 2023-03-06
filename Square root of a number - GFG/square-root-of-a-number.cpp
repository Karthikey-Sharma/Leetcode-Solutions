//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x == 1 || x == 0) return x;
        long long int lo = 1;
        long long int hi = x;
        while(lo <= hi){
            long long int mid = lo + (hi - lo) / 2;
            if((mid) < x / mid){
                lo = mid + 1;
            }else if((mid ) > x / mid){
                hi = mid - 1;
            }else{
                return mid;
            }
        }
        return hi;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends