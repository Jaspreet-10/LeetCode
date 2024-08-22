class Solution {
public:
    void findCombinations(int index, int n, vector<int>&candidates, vector<vector<int>>&ans,
    map<vector<int>,int>&m, int target, vector<int>&temp){
        if(index>=n || target<0) return ;
        if(target == 0){
            if(m[temp] == 0) ans.push_back(temp);
            return ;
        }
        temp.push_back(candidates[index]);
        findCombinations(index, n, candidates, ans, m, target-candidates[index], temp);
        temp.pop_back();
        findCombinations(index+1, n, candidates, ans, m, target, temp);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        map<vector<int>, int>m;
        findCombinations(0, candidates.size(),candidates, ans, m, target, temp);
        return ans;
    }
};