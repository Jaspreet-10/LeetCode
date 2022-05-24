class Solution {
public:
    int totalWays(int index,vector<int>& candidates,vector<int>&bt,vector<vector<int>>&ans,int target){
        if(target==0){
            ans.push_back(bt);
            return 0;
        }
        if(index>=candidates.size())
            return 0;
        if(candidates[index]<=target){
            bt.push_back(candidates[index]);
            totalWays(index,candidates,bt,ans,target-candidates[index]);
            bt.pop_back();
        }
        totalWays(index+1,candidates,bt,ans,target);
        return 0;
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>bt;
        vector<vector<int>>ans;
        totalWays(0,candidates,bt,ans,target);
        return ans;
    }
};