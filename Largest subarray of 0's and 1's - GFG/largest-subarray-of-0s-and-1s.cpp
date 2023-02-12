//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
class Solution{
  public:
    int maxLen(int nums[], int n )
    {
        unordered_map<int , int> map;
        map[0] = -1;
        int curr_sum = 0;
        int max_len = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0){
                curr_sum -= 1;
            }else{
                curr_sum += 1;
            }

            if(map.find(curr_sum) != map.end()){
                int len = i - map[curr_sum];
                if(len > max_len){
                    max_len = len;
                }
            }else{
                map[curr_sum] = i;
            }
        }
        return max_len;
    }
};


//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends