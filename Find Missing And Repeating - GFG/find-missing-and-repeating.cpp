//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int xorVal = 0;
        for(int i = 0 ; i < n ; i++){
            xorVal ^= arr[i];
        }
        
        for(int i = 1 ; i <= n ; i++){
            xorVal ^= i;
        }
        
        int rsbm = xorVal & - xorVal;
        int x = 0;
        int y = 0;
        
        for(int i = 0 ; i < n ; i++){
            int val = arr[i];
            if((val & rsbm) == 0){
                x ^= val;
            }else{
                y ^= val;
            }
        }
        
        for(int i = 1 ; i <= n ; i++){
            int val = i;
            if((val & rsbm) == 0){
                x ^= val;
            }else{
                y ^= val;
            }
        }
        
        
        int * a = new int[2];
        for(int i = 0 ; i < n ; i++){
            if(arr[i] == x){
                a[0] = x;
                a[1] = y;
            }else if(arr[i] == y){
                a[0] = y;
                a[1] = x;
            }
        }
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends