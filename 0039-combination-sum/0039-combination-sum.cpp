class Solution {
public:
    vector<vector<int>>findTarget(int index, vector<int>& candidates, int target, vector<int>temp, vector<vector<int>>&ans){
        if(index>=candidates.size() || target<0) return ans;
        if(target == 0){
            ans.push_back(temp);
            return ans;
        }
        if(candidates[index]<=target){
        temp.push_back(candidates[index]);
        findTarget(index, candidates, target-candidates[index], temp, ans);
        temp.pop_back();
        }
        findTarget(index+1, candidates, target,temp, ans);
        return ans;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        return findTarget(0, candidates, target, temp, ans);
    }
};