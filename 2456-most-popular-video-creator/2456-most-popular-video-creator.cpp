class Solution {
public:
    class info{
        public:
        int maxView;
        string small;
        int sum = 0;
    };
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string , info> map;
        int maxim = 0;
        for(int i = 0 ; i < creators.size() ; i++){
            if(map.find(creators[i]) == map.end()){
                map[creators[i]].maxView = views[i];
                map[creators[i]].small = ids[i];
                map[creators[i]].sum += views[i];
                 maxim = max(maxim , views[i]);
            }else{
               map[creators[i]].sum += views[i];
               if(map[creators[i]].maxView < views[i] || map[creators[i]].maxView == views[i] && ids[i] < map[creators[i]].small){
                   map[creators[i]].small = ids[i];
                   map[creators[i]].maxView = views[i];
               }
                maxim = max(map[creators[i]].sum , maxim);
            }
           
        }
        vector<vector<string>> ans;
        for(auto it : map){
            if(it.second.sum == maxim){
                ans.push_back({it.first , it.second.small});
            }
        }
        return ans;
    }
};