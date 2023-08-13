//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string pattern){
        string ans = "";
        int num = 1;
        stack<int> stack;
        for(int i = 0 ; i < pattern.size() ; i++){
            char ch = pattern[i];
            if(ch == 'D'){
                stack.push(num);
                num++;
            }else{
                stack.push(num);
                num++;
                while(stack.size() > 0){
                    ans.push_back(stack.top() + '0');
                    stack.pop();
                }
            }
        }
        stack.push(num);
        while(stack.size() > 0){
            ans.push_back(stack.top() + '0');
            stack.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends