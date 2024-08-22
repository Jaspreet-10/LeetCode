class Solution {
public:
    void findSubsets(int index, vector<int>&nums, vector<vector<int>>&ans, int n,
        unordered_map<int,int>&m, vector<int>&temp){
            if(index>=n){
                ans.push_back(temp);
                return ;
            }
            temp.push_back(nums[index]);
            findSubsets(index+1, nums, ans, n, m, temp);
            temp.pop_back();
            findSubsets(index+1, nums, ans, n, m, temp);
            return;
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int, int>m;
        vector<int>temp;
        findSubsets(0, nums, ans,  nums.size(), m, temp);
        return ans;
    }
};