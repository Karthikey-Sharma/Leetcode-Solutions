//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i = -1;
        int j = -1;
        int max_len = -1;
        unordered_map<char , int> map;
        while(true){
            bool flag1 = false;
            bool flag2 = false;
            // acquire
            while(i < (int) s.size() - 1){
                flag1 = true;
                i++;
                char ch = s[i];
                map[ch]++;
                if(map.size() < k){
                    continue;
                }else if(map.size() == k){
                    int len = (i - j);
                    if(len > max_len){
                        max_len = len;
                    }
                }else{
                    break;
                }
            }
            // release
            while(j < i){
                flag2 = true;
                j++;
                char ch = s[j];
                map[ch]--;
                if(map[ch] == 0) {
                    map.erase(ch);
                }
                
                if(map.size() > k){
                    continue;
                }else if(map.size() == k){
                    int len = i - j;
                    if(len > max_len){
                        max_len = len;
                    }
                    break;
                }
            }
            
            if(flag1 == false && flag2 == false){
                break;
            }
        }
        return max_len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends