//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) {
	    string ans = "";
        long long q = numerator / denominator;
        long long r = numerator % denominator;
        ans += to_string(q);
        if(r == 0){
            return ans;
        }else{
            ans += ".";
            unordered_map<int , int> map;
            while(r != 0){
                if(map.find(r) != map.end()){
                    ans.insert(map[r] , "(");
                    ans += ")";
                    break;
                }else{
                    map[r] = ans.size();
                    r *= 10;
                    q = r / denominator;
                    r = r % denominator;
                    ans += to_string(q);
                }
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends