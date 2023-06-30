//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
        stack<char> stack;
        for(char ch : S){
            while(!stack.empty() && stack.top() > ch && k > 0){
                stack.pop();
                k--;
            }
            stack.push(ch);
        }
        while(k > 0 && !stack.empty()){
            stack.pop();
            k--;
        }
        string ans = "";
        while(!stack.empty()){
            ans += stack.top();
            stack.pop();
        }
        
        reverse(ans.begin() , ans.end());
        int i = 0;
        while(ans[i] == '0')i++;
        ans = ans.substr(i);
        if(ans.size() == 0) return "0";
        else return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends