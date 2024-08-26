class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int a = intervals[0][0], b = intervals[0][1];
        for(int i = 0 ; i < intervals.size() ; ++i){
            if(intervals[i][0]<=b){
                b = max(intervals[i][1],b);
            }else{
                ans.push_back({a,b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }
        ans.push_back({a,b});
        return ans;
    }
};