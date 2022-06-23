class Solution {
public:
    void printPermutations(vector<int>&nums,vector<vector<int>>&ans,vector<int>ds,vector<bool>freq)     {
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0 ; i < nums.size() ; ++i){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=true;
                printPermutations(nums,ans,ds,freq);
                freq[i]=false;
                ds.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<bool>freq(nums.size(),false);
        printPermutations(nums,ans,ds,freq);
        return ans;
    }
};