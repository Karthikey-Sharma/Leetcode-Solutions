//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        int count = 0;
        int j = -1;
        int max_len = 0;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0) count++;
            while(count > k){
                j++;
                if(nums[j] == 0) count--;
            }
            int len = i - j;
            max_len = max(max_len , len);
        }
        return max_len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends