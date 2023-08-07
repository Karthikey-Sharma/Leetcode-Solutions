//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    void dfs(unordered_map<int , vector<int>> & adj , int src , vector<bool>& visited , int V){
        visited[src] = true;
        for(int nbr : adj[src]){
            if(!visited[nbr]){
                ans.push_back(nbr);
                dfs(adj , nbr , visited , V);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int , vector<int>> graph;
        for(int i = 0 ; i < V ; i++){
           for(int u : adj[i]){
               graph[i].push_back(u);
               graph[u].push_back(i);
           }
        }
        ans.push_back(0);
        vector<bool> visited(V , 0);
        dfs(graph , 0 , visited , V);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends