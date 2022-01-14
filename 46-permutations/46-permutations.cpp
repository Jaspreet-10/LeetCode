class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        int i=0;
        do{
                v.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return v;
    }
};