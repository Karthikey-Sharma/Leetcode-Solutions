//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	bool isValid(int ni , int nj , int n){
        if(ni >= 0 && nj >= 0 && ni < n && nj < n){
            return true;
        }
        else return false;
    }
	double findProb(int n,int row , int column, int k)
	{
	     vector<vector<double>> next(n , vector<double>(n , 0));
        vector<vector<double>> curr(n , vector<double>(n , 0));
        curr[row][column] = 1;
        for(int move = 0 ; move < k ; move++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(curr[i][j] > 0){
                        int ni = 0 ;
                        int nj = 0;
                        
                        ni = i - 2;
                        nj = j + 1;
                        if(isValid(ni , nj , n)){
                            next[ni][nj] += curr[i][j] / 8.0;
                        }
                        ni = i - 1;
                        nj = j + 2;
                        if(isValid(ni , nj , n)){
                            next[ni][nj] += curr[i][j] / 8.0;
                        }
                        ni = i + 1;
                        nj = j + 2;
                        if(isValid(ni , nj , n)){
                            next[ni][nj] += curr[i][j] / 8.0;
                        }
                        ni = i + 2;
                        nj = j + 1;
                        if(isValid(ni , nj , n)){
                            next[ni][nj] += curr[i][j] / 8.0;
                        }
                        ni = i + 2;
                        nj = j - 1;
                        if(isValid(ni , nj , n)){
                            next[ni][nj] += curr[i][j] / 8.0;
                        }
                        ni = i + 1;
                        nj = j - 2;
                        if(isValid(ni , nj , n)){
                            next[ni][nj] += curr[i][j] / 8.0;
                        }
                        ni = i - 1;
                        nj = j - 2;
                        if(isValid(ni , nj , n)){
                            next[ni][nj] += curr[i][j] / 8.0;
                        }
                        ni = i - 2;
                        nj = j - 1;
                        if(isValid(ni , nj , n)){
                            next[ni][nj] += curr[i][j] / 8.0;
                        }
                    }
                }
            }
            curr = next;
            fill(next.begin() , next.end() , vector<double>(n , 0));
        }

        double sum = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                sum += curr[i][j];
            }
        }
        return sum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends