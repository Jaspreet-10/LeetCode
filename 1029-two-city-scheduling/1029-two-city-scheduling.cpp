class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size(),ans=0,halfPeople=(n*2)/2;
        vector<pair<int,pair<int,int>>>p(n,make_pair(0,make_pair(0,0)));
        for(int i=0;i<n;++i){
            p[i].first=costs[i][1]-costs[i][0];
            p[i].second.first=costs[i][0];
            p[i].second.second=costs[i][1];
        }
        sort(p.begin(),p.end());
        for(int i=n-1;i>=0;--i){
            if(i>=(halfPeople/2))
                ans+=p[i].second.first;
            else
                ans+=p[i].second.second;
        }
        return ans;
    }
};