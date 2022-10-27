class Solution {
public:
    
    int numDistinct(string s, string t) {
        // shifting 1 index to handle negative base case for tabulation
        // space optimization
        
        vector<double> prev(t.size() + 1);
        vector<double> curr(t.size() + 1);
        for(int i = 0 ; i <= s.size() ; i++){
            for(int j = 0 ; j <= t.size() ; j++){
                if(j == 0){
                    prev[j] =  1;
                    continue;
                }
                if(i == 0){
                    prev[j] =  0;
                    continue;
                } 
                
                if(s[i - 1] == t[j - 1]){
                    curr[j] = prev[j - 1] + prev[j];
                }
                else curr[j] =  prev[j];
            }
            prev = curr;
        }
        return (int)prev[t.size()];
    }
};