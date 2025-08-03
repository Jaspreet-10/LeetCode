class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        if(intervals.size()<1) return true;
       vector<pair<int,int>>v;
        for(int i = 0 ; i < intervals.size() ; ++i){
            v.push_back({intervals[i][1], intervals[i][0]});
        }
        sort(v.begin(),v.end());
        int e = v[0].first;
        int s = v[0].second;
        for(int i = 1 ; i < intervals.size() ; ++i){
            if(e<=v[i].second){
                e = v[i].first;
            }else return false;
        }
        return true;
    }
};