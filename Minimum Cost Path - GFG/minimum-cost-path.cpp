//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    /// first = distance
    // second.first = u
    // second.second = v
   bool isValid(int x, int y, int N) {
    if (x >= 0 && x < N && y >= 0 && y < N)
        return true;
    return false;
}

vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int minimumCostPath(vector<vector<int>>& grid) {
    int N = grid.size();
    vector<vector<int>> distances(N, vector<int>(N, INT_MAX));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    
    distances[0][0] = grid[0][0];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({grid[0][0], {0, 0}});

    while (!pq.empty()) {
        auto node = pq.top();
        int dist = node.first;
        int u = node.second.first;
        int v = node.second.second;

        pq.pop(); // Remove the processed node from the priority queue
        

        visited[u][v] = true;

        for (vector<int> dir : dirs) {
            int xx = u + dir[0];
            int yy = v + dir[1];

            if (isValid(xx, yy, N) && !visited[xx][yy]) {
                int newDist = dist + grid[xx][yy];
                if (newDist < distances[xx][yy]) {
                    distances[xx][yy] = newDist;
                    pq.push({newDist, {xx, yy}});
                }
            }
        }
    }

    return distances[N - 1][N - 1];
}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends