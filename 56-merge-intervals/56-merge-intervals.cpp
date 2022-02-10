class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        vector<int>temp(2);
        sort(intervals.begin(),intervals.end());
        temp[0]=intervals[0][0];
        temp[1]=intervals[0][1];
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<=temp[1]){
                temp[1]=max(temp[1],intervals[i][1]);
            }else{
                res.push_back(temp);
                temp[0]=intervals[i][0];
                temp[1]=intervals[i][1];
            }
        }
        res.push_back(temp);
        return res;
    }
};