//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int i , int j , int N , int M){
        if(i >= 0 && i < N && j >= 0 && j < M) return true;
        return false;
    }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0] == 0 || A[X][Y] == 0) return -1;
        vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<bool>> visited(N , vector<bool>(M , false));
        visited[0][0] = true;
        queue<pair<int , int>> q;
        q.push({0 , 0});
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++){
                pair<int , int> front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;
                if(x == X && y == Y) return level;
                for(vector<int> dir : dirs ){
                    int xx = x + dir[0];
                    int yy = y + dir[1];
                    
                    if(isValid(xx , yy , N , M) && A[xx][yy] == 1 && visited[xx][yy] == false){
                        visited[xx][yy] = true;
                        q.push({xx , yy});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends