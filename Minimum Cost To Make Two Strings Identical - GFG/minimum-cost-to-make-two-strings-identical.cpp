//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public: 
	int dp[1005][1005];
    int getSum(string s , int idx , int cost){
        int sum = 0;
        for(int ii = idx - 1 ; ii >= 0; ii--){
            sum += cost;
        }
        return sum;
    }
    int rec(string s1 , string s2 , int i , int j , int costX , int costY){
        if(i == 0){
           int sum = getSum(s2, j , costY);
           return dp[i][j] = sum;
        }
        if(j == 0){
            int sum = getSum(s1 , i , costX);
            return  dp[i][j] = sum;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i - 1] == s2[j - 1]) return dp[i][j] =  rec(s1 , s2 , i - 1 , j - 1 , costX , costY);
        else {
            return dp[i][j] = min(rec(s1 , s2 , i - 1 , j , costX , costY ) + costX , rec(s1 , s2 , i , j - 1 , costX , costY) + costY);
        }
    }
	int findMinCost(string X, string Y, int costX, int costY)
	{
	    for(int i = 0 ; i <= X.size() ; i++){
	        for(int j = 0 ; j <= Y.size() ; j++){
	            dp[i][j] = -1;
	        }
	    }
	    return rec(X , Y , X.size() , Y.size() ,  costX , costY);
	}
  

};
	

//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
       	string x, y;
       	cin >> x >> y;
        
       	int costX, costY;
       	cin >> costX >> costY;

        

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends