//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int , int> map;
        int i = 0;
        for( ; i < k - 1; i++){
            if(map.find(A[i]) != map.end()){
                map[A[i]]++;
            }else{
                map.insert({A[i] , 1});
            }
        }
        i--;
        int j = -1;
        while(i < n - 1){
            i++;
            // Acquire
            if(map.find(A[i]) != map.end()){
                map[A[i]]++;
            }else{
                map.insert({A[i] , 1});
            }
            // work
            ans.push_back(map.size());
            // release
            j++;
            int freq = map[A[j]];
            if(freq == 1){
                map.erase(A[j]);
            }else{
                map[A[j]]--;
            }
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends