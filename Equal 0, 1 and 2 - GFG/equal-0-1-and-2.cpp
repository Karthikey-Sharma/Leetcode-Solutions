//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string arr) {
    long long count  = 0;
    int n = arr.size();
    unordered_map<string , int> map;
    int countOfZeros = 0;
    int countOfOnes = 0;
    int countOfTwos = 0;
    int delta1 = countOfOnes - countOfZeros;
    int delta2 = countOfTwos - countOfOnes;
    string key = to_string(delta1) + "#" + to_string(delta2);
    map[key] = 1;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == '0'){
            countOfZeros++;
        }else if(arr[i] == '1'){
            countOfOnes++;
        }else{
            countOfTwos++;
        }
        
        int delta1 = countOfOnes - countOfZeros;
        int delta2 = countOfTwos - countOfOnes;
        string key = to_string(delta1) + "#" + to_string(delta2);
        if(map.find(key) != map.end()){
            count += map[key];
            map[key]++;
        }else{
            map[key]++;
        }
    }
    return count;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends