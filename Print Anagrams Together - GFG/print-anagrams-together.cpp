//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> map;
        for(int i = 0 ;i < strs.size() ; i++){
            string str = strs[i];
            sort(strs[i].begin() , strs[i].end());
            map[strs[i]].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto it : map){
            vector<string> strings = it.second;
            vector<string> partialAns;
            for(int i = 0 ; i < strings.size() ; i++){
                partialAns.push_back(strings[i]);
            }
            ans.push_back(partialAns);
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
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends