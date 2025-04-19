class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        int count = 1;
        sort(intervals.begin(), intervals.end());
        int end = intervals[0][1];
        for(int i = 1 ; i < intervals.size() ; ++i){
            if(intervals[i][0]<=end){
                end = min(intervals[i][1], end);
            }else{
                end = intervals[i][1];
               ++count;
            }
        }
        return count;
    }
};