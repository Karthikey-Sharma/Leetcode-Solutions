//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long subCount(long long nums[], int n, long long K)
	{
	      
        vector<long long> map(K);
        map[0] = 1;

        long long ans = 0;

        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int rem = sum % K;

            if(rem < 0){
                rem += K;
            }

            ans += map[rem];

            map[rem]++;
        }

        return ans;
	}



};


//{ Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends