//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        stack<char> stack;
        string ans = "";
        for(char ch : s){
            if(ch == '('){
                if(stack.size() > 0) ans += ch;
                stack.push(ch);
            }else{
                stack.pop();
                if(stack.size() > 0) ans += ch;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends