//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> stack;
        for(int i = 0 ; i < n ; i++) stack.push(i);
        
        while(stack.size() > 1){
            int val1 = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();
            
            if(M[val1][val2] == 1){
                // val1 knows val2
                stack.push(val2);
            }else{
                // val2 knows val1
                stack.push(val1);
            }
        }
        int val = stack.top();
        stack.pop();
        bool flag = true;
        for(int i = 0 ; i < n ; i++){
            if(i == val) continue;
            else if(M[val][i] ==  true) flag = false;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(i == val) continue;
            else if(M[i][val] == false) flag = false;
        }
        
        if(flag) return val;
        else return -1;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends