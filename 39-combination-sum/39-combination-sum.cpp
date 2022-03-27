class Solution {
public:
    vector<vector<int>>res;
vector<vector<int>> uniqueCombinations(int index,int target,vector<int>& candidates, vector<int>&v){
    if(target==0){
        res.push_back(v);
        return res;
    }
    if(index>=candidates.size())
        return res;
    // pair<vector<int>,int> currentKey = {v,target};
    // if(memo.find(currentKey)!=memo.end())
    //     return res;
    int consider=0;
    if(candidates[index]<=target){
        v.push_back(candidates[index]);
        uniqueCombinations(index,target-candidates[index],candidates,v);
        v.pop_back();
    }
    uniqueCombinations(index+1,target,candidates,v);
    // memo[currentKey] = res;
    return res;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return res;
        vector<int>ds;
        // map<pair<vector<int>,int>,vector<vector<int>>>memo;
        return uniqueCombinations(0,target,candidates,ds);
    }
};