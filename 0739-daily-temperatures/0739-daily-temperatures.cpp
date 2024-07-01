class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0 ; i < temperatures.size() ; ++i){
            while(!pq.empty() and pq.top().first<temperatures[i]){
                ans[pq.top().second] = i-pq.top().second;
                pq.pop();
            }
            pq.push({temperatures[i],i});
        }
        return ans;
    }
};