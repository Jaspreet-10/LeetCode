class Solution {
public:
    void printPermutations(vector<int>&nums,vector<vector<int>>&res,
    vector<int>&v, unordered_map<int,int>&m){
        if(v.size() == nums.size()){
            res.push_back(v);
            return ;
        }
        for(int i = 0 ; i < nums.size() ; ++i){
            if(m[i] == 0){
                m[i] = 1;
                v.push_back(nums[i]);
                printPermutations(nums,res,v,m);
                v.pop_back();
                m[i] = 0;
            }
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        unordered_map<int,int>m;
        vector<int>v;
        printPermutations(nums,res,v,m);
        return res;
    }
};