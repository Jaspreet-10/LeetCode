class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>, vector<pair<double,vector<int>>>,
        greater<pair<double,vector<int>>>>pq;
        vector<vector<int>>ans;
        for(int i = 0 ; i < points.size() ; ++i){
            // pq.push({sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1])), 
            // {points[i][0],points[i][1]}});
            pq.push({sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1])), 
            {points[i][0],points[i][1]}});
        }
        while(!pq.empty() and k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            --k;
        }
        return ans;
    }
};