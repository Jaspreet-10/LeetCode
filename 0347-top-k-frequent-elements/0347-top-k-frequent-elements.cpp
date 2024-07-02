class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>m;
        for(int i = 0 ; i < nums.size() ; ++i){
            m[nums[i]]++;
        }
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        vector<int>res;
        while(k>0 and !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            --k;
        }
        return res;
    }
};