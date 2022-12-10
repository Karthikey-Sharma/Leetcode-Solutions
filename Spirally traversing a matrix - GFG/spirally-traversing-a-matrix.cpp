//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int minr = 0;
        int minc = 0;
        int maxr = matrix.size() - 1;
        int maxc = matrix[0].size() - 1;
        vector<int> spiralMatrix;
        int tne = matrix.size() * matrix[0].size();
        int cnt = 0;
        while(cnt < tne){
            //top wall
            for(int j = minc , i = minr ; j <= maxc && cnt < tne; j++){
                spiralMatrix.push_back(matrix[i][j]);
                cnt++;
            }
            minr++;

            // leftWall
            for(int i = minr , j = maxc ; i <= maxr && cnt < tne; i++){
                spiralMatrix.push_back(matrix[i][j]);
                cnt++;
            }
            maxc--;

            // bottom wall
            for(int j = maxc , i = maxr ; j >= minc && cnt < tne ; j--){
                spiralMatrix.push_back(matrix[i][j]);
                cnt++;
            }
            maxr--;

            // right wall
            for(int i = maxr , j = minc ; i >= minr && cnt < tne ; i--){
                spiralMatrix.push_back(matrix[i][j]);
                cnt++;
            }
            minc++;
        }
        return spiralMatrix;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends