//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    bool compare(unordered_map<char , int>& patternMap , unordered_map<char , int>& anagramCheckerMap){
        for(auto it : patternMap){
            if(anagramCheckerMap.find(it.first) == anagramCheckerMap.end() || anagramCheckerMap[it.first] != it.second){
                return false;
            }
        }
        return true;
    }
	int search(string p, string s) {
	    unordered_map<char , int> patternMap;
        unordered_map<char , int> anagramCheckerMap;
        int count  = 0;
        for(char val : p){
            patternMap[val]++;
        }

        for(int i = 0 ; i < p.size() ; i++){
            anagramCheckerMap[s[i]]++;
        }

        int j = 0;
        int i = p.size();
        while(i < s.size()){
            if(compare(patternMap , anagramCheckerMap)){
                count++;
            }

            char val = s[i];
            anagramCheckerMap[val]++;
            char valToBeRemoved = s[i - p.size()];
            if(anagramCheckerMap[valToBeRemoved] == 1){
                anagramCheckerMap.erase(valToBeRemoved);
            }else{
                anagramCheckerMap[valToBeRemoved]--;
            }
            i++;
        }
        if(compare(patternMap , anagramCheckerMap)){
            count++;
        }
        return count;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends