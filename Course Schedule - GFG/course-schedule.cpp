//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[N];
	    for(vector<int>& pairs : prerequisites){
	        adj[pairs[1]].push_back(pairs[0]);
	    }
	    
	    vector<int> in(N , false);
	    for(int i = 0 ; i < N ; i++){
	        for(auto& dest : adj[i]){
	            in[dest]++;
	        }
	    }
	    
	    queue<int> q;// jiski indegree 0 hai wo q mein push krenge bas
	    for(int i = 0 ; i < N ; i++){
	        if(in[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(q.size() != 0){
	        int front = q.front();
	        q.pop();
	        topo.push_back(front);
	        for(auto & nbr : adj[front]){
	            in[nbr]--;
	            if(in[nbr] == 0){
	                q.push(nbr);
	            }
	        }
	    }
	    if(topo.size() == N) return topo;
	    else return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends