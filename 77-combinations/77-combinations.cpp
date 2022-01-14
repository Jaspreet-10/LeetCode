class Solution {
public:
    void solve(vector<int>nums,int index,vector<vector<int>>&ans,vector<int>&output,int k)
    {
        if(output.size()==k)
        {
            ans.push_back(output);
            return;
        }
        for(int j=index;j<nums.size();j++)
        {
            output.push_back(nums[j]);
            solve(nums,j+1,ans,output,k);
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        int index=0;
        vector<vector<int>>ans;
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        vector<int>output;
        solve(nums,index,ans,output,k);
        return ans;
    } 
};