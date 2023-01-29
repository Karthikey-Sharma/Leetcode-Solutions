//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    int i= 0;
    int j = 0;
    unordered_set<int> set;
    int maxim = 0;
    while(i < s.size()){
        if(set.find(s[i]) == set.end()){
            set.insert(s[i]);
            maxim = max(maxim , (i - j + 1));
            i++;
        }else{
            set.erase(s[j]);
            j++;
        }
    }
    return maxim;
}