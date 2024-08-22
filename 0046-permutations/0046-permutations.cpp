class Solution {
public:
    void findPermutations(int index, int n, vector<int>&nums, vector<vector<int>>&ans, 
    unordered_map<int,int>&m, vector<int>&temp){
        if(temp.size() == n){
            ans.push_back(temp);
            return ;
        }
        for(int i = 0 ; i < n ; ++i){
            if(m[i] == 0){
                temp.push_back(nums[i]);
                m[i] = 1;
                findPermutations(index+1, n, nums, ans, m, temp);
                m[i] = 0;
                temp.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        unordered_map<int,int>m;
        findPermutations(0, nums.size(),nums, ans, m, temp);
        return ans;
    }
};