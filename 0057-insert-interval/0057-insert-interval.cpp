class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1 ; i < intervals.size() ; ++i){
            if(intervals[i][0]<=end){
                end = max(end, intervals[i][1]);
            }else{
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};