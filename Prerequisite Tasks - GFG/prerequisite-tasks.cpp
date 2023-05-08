//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(pair<int , int>& pairs : prerequisites){
	        adj[pairs.second].push_back(pairs.first);
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
	    if(topo.size() == N) return true;
	    else return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends