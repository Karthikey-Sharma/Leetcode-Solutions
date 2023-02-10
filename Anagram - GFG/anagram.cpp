//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string s, string t){
        
        unordered_map<char , int> map;
        if(s.size() != t.size()) return false;
        for(int i = 0 ; i < s.size() ; i++){
            map[s[i]]++;
        }

        for(int i = 0 ; i < t.size() ; i++){
            if(map[t[i]] == 1){
                map.erase(t[i]);
            }else{
                map[t[i]]--;
            }
        }
        return map.size() == 0;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends