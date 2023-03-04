//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> nums, long long target)
    {
        pair<long , long> ans;
        long  leftMost = -1;
        long  rightMost = -1;
        int lo = 0;
        int hi = (int)nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target){
                lo = mid + 1;
            }else if(nums[mid] > target){
                hi = mid - 1;
            }else{
                leftMost = mid;
                hi = mid - 1;
            }
        }
        
        lo = 0;
        hi = (int)nums.size() - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] < target){
                lo = mid + 1;
            }else if(nums[mid] > target){
                hi = mid - 1;
            }else{
                rightMost = mid;
                lo = mid + 1;
            }
        }

        ans = {leftMost , rightMost};
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends