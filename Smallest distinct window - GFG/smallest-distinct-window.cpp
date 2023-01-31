//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int solution(string str){
        int len = INT_MAX;
        unordered_set<char> s;
        for(int i = 0 ; i < str.size() ; i++){
            s.insert(str[i]);
        }
        int i = -1;
        int j = -1;
        unordered_map<char , int> map;
        map.clear();
        
        while(true){
            bool flag1 = false;
            bool flag2 = false;
            
            // acquire till it is invalid(map.size() < set.size())
            while((i < (int)str.size() - 1) && (map.size() < s.size())){
                
                i++;
                map[str[i]]++;
                flag1 = true;
            }
           // collect and release
            while((j < i) && (map.size() == s.size())){
                int potential_length = i - j;
                if( potential_length < len){
                    len = potential_length;
                }
                j++;
                char ch = str[j];
                if(map[ch] == 1){
                    map.erase(ch);
                }
                else{
                    map[ch]--;
                }
                flag2 = true;
            }
            
            if(flag1 == false && flag2 == false){
                break;
            }
            
        }
        
        return len;
    }
    int findSubString(string str)
    {
        return solution(str) ;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends