//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         sort(intervals.begin() , intervals.end());
        stack<vector<int>> stack;
        for(int i = 0 ; i < intervals.size() ; i++){
            if(stack.size() > 0 && stack.top()[1] >= intervals[i][0]){
                int st = stack.top()[0];
                int end = max(stack.top()[1] , intervals[i][1]);
                stack.pop();
                stack.push({st , end});
            }else{
                stack.push(intervals[i]);
            }
        }
        vector<vector<int>> ans;
        while(stack.size() > 0){
            ans.push_back(stack.top());
            stack.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends