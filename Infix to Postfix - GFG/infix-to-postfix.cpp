//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char op){
        if(op == '+' || op == '-') return 1;
        else if(op == '*' || op == '/') return 2;
        else return 3;
    }
    string infixToPostfix(string s) {
        stack<string> post ;
        stack<char> ops;
        
        for(int i= 0 ; i < s.size() ;i++){
            char ch = s[i];
            if(ch == '('){
                ops.push(ch);
            }else if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
                string abc="";
                abc.push_back(ch);
                post.push(abc);
            }else if(ch == ')'){
                while(ops.top() != '('){
                    char op = ops.top();
                    ops.pop();
                    string val2 = post.top();
                    post.pop();
                    string val1 = post.top();
                    post.pop();
                    string postVal = val1 + val2 + op;
                    post.push(postVal);
                }
                ops.pop();
            }else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
                while(ops.size() > 0 && ops.top() != '(' && precedence(ch) <= precedence(ops.top())){
                    char op = ops.top();
                    ops.pop();
                    string val2 = post.top();
                    post.pop();
                    string val1 = post.top();
                    post.pop();
                    string postVal = val1 + val2 + op;
                    post.push(postVal);
                }
                ops.push(ch);
            }
        }
        
        while(ops.size() > 0 ){
                    char op = ops.top();
                    ops.pop();
                    string val2 = post.top();
                    post.pop();
                    string val1 = post.top();
                    post.pop();
                    string postVal = val1 + val2 + op;
                    post.push(postVal);
        }
        return post.top();
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends