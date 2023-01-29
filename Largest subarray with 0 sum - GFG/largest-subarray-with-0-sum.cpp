//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        unordered_map<int , int> map;
        int max_len = 0;
        int sum = 0;
        map[0] = -1;
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(map.find(sum) == map.end()){
                map[sum] = i;
            }else{
                int len = i - map[sum];
                max_len = max(max_len , len);
            }
        }
        return max_len;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends