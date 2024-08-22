class Solution {
public:
    void findCombinations(int index, int n, vector<int>&candidates, vector<vector<int>>&ans,
     int target, vector<int>&temp){
        if(index>=n) return ;
        if(target == 0){
           ans.push_back(temp);
           return ;
        }
        if(candidates[index]<=target){
        temp.push_back(candidates[index]);
        findCombinations(index, n, candidates, ans, target-candidates[index], temp);
        temp.pop_back();
        }
        findCombinations(index+1, n, candidates, ans, target, temp);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        findCombinations(0, candidates.size(),candidates, ans, target, temp);
        return ans;
    }
};