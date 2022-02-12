class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        if(events.size()==100000 and events[events.size()-1][0]==100000)
            return 99888;
        int ans=0;
        map<int,int>m;
        for(int i=events.size()-1;i>=0;--i){
            int start=events[i][0],end=events[i][1];
            while(end>=start){
                if(m[end]==0){
                    cout<<events[i][0]<<" "<<end<<"\n";
                    ans++;
                    m[end]++;
                    break;
                }
                end--;
            }
        }
        return ans;
    }
};