//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
         int minr = 0;
        int minc = 0;
        int maxr = n - 1;
        int maxc =m - 1;
        int tne = k;
        int cnt = 1;
        int ans = -1;
        while(cnt <= tne){
            //top wall
            for(int j = minc , i = minr ; j <= maxc && cnt <= tne; j++){
                if(cnt == k) return a[i][j];
                cnt++;
            }
            minr++;

            // leftWall
            for(int i = minr , j = maxc ; i <= maxr && cnt <= tne; i++){
                if(cnt == k) return a[i][j];
                cnt++;
            }
            maxc--;

            // bottom wall
            for(int j = maxc , i = maxr ; j >= minc && cnt <= tne ; j--){
                if(cnt == k) return a[i][j];
                cnt++;
            }
            maxr--;

            // right wall
            for(int i = maxr , j = minc ; i >= minr && cnt <= tne ; i--){
                if(cnt == k) return a[i][j];
                cnt++;
            }
            minc++;
        }
        return ans;
        
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends