class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>>m;
        vector<pair<int,int>>avgV;
        vector<vector<int>>ans;
        int count = 0, sum = 0;
        for(int i = 0 ; i < items.size() ; ++i){
            m[items[i][0]].push_back(items[i][1]);
        }
        for(auto it:m){
            vector<int>v = it.second;
            int sum = 0, count = 0;
            sort(v.begin(), v.end());
            for(int i = v.size()-1;i>=0;--i){
                sum+=v[i];
            ++count;
            if(count == 5) break;
            }
            int avg = sum/5;
            avgV.push_back({avg, it.first});
        }
        sort(avgV.begin(), avgV.end());
        for(int i = avgV.size()-1;i>=0;--i){
            ans.push_back({avgV[i].second, avgV[i].first});
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};