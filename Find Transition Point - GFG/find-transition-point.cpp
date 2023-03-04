//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    int lo = 0;
    int hi = n - 1;
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == 0){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }
    if(arr[lo] != 1) return -1;
    else return lo;
}