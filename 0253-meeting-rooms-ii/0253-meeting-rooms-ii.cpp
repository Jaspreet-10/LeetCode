class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
      if(intervals.size() == 0) return 0;
        vector<int>start,end;
        int count = 1, i = 1, j = 0;
        for(int i = 0 ; i < intervals.size() ; ++i){
           start.push_back(intervals[i][0]);
           end.push_back(intervals[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        while(i<start.size()){
            if(start[i]>=end[j]){
                ++i,++j;
            }else{
                ++count;
                ++i;
            }
        }
        return count;
    }
};