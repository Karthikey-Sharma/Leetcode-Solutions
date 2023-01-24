//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> arr, int k) {
        unordered_map<int , int> map;
        for(int i = 0 ; i < arr.size() ; i++){
            int rem = (arr[i] + k) % k;
            map[rem]++;
        }

        for(auto it : map){
            if(it.first == 0){
                if(it.second % 2 != 0) return false;
            }else if(2 * (it.first) == k){ // k / 2 wala case
                if(it.second % 2 != 0) return false;
            }else{
                if(it.second != map[k - it.first]){
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends