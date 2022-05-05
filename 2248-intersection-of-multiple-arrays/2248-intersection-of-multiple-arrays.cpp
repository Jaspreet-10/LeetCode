class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int>m;
        vector<int>v;
        for(int i = 0 ; i < nums.size() ; ++i){
            for(int j = 0 ; j < nums[i].size() ; ++j){
                m[nums[i][j]]++;
            }
        }
       for(auto it:m){
           if(it.second == nums.size())
               v.push_back(it.first);
       }
        sort(v.begin(),v.end());
        return v;
    }
};