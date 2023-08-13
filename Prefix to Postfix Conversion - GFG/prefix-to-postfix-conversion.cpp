//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string &exp) {
      int n = exp.size();
       stack<string> infix;
       for(int i = n - 1 ; i >= 0 ; i--){
           char ch = exp[i];
           if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
               string val = "";
               val.push_back(ch);
               infix.push(val);
           }else{
               string op = "";
               op.push_back(ch);
               
               string val1 = infix.top();
               infix.pop();
               
               string val2 = infix.top();
               infix.pop();
               
               string val =  val1 + val2 + op;
               infix.push(val);
           }
       }
       return infix.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends