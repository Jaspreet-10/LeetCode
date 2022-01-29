class Solution {
public:
    vector<vector<int>>res;
    void uniqueCombinations(int index,int target,vector<int>c,vector<int>ans){
        if(index==c.size()){
            if(target==0)
            res.push_back(ans);
            return ;
        }
        if(c[index]<=target){
        ans.push_back(c[index]);
        uniqueCombinations(index,target-c[index],c,ans);
        ans.erase(ans.begin()+ans.size()-1);
        }
        uniqueCombinations(index+1,target,c,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()) return res;
        vector<int>ds;
        uniqueCombinations(0,target,candidates,ds);
        return res;
    }
};