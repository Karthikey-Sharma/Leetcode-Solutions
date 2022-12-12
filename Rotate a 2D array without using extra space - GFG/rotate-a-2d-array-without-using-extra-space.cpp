//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& matrix, int n) {
	    // transpose
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = i ; j < matrix[0].size() ; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // reverse col
        for(int j = 0 ; j < matrix[0].size() ; j++){
            int li = 0;
            int ri = matrix.size() - 1;
            while(li < ri){
                int temp = matrix[li][j];
                matrix[li][j] = matrix[ri][j];
                matrix[ri][j] = temp;
                li++;
                ri--;
            }
        }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++) {
            vector<int> a;
            for (int j = 0; j < n; j++) {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends