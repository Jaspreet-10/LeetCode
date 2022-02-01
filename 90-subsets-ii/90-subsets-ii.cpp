class Solution {
public:
    vector<int>v;
    vector<vector<int>>res;
    map<vector<int>,int>m;
    void subsetsWithoutDup(int index,vector<int>nums,vector<int>v,int n){
        if(index==n){
            sort(v.begin(),v.end());
            if(m[v]!=1){
                res.push_back(v);
                m[v]=1;
            }else{
                v.clear();
            }
            return ;
        }
        subsetsWithoutDup(index+1,nums,v,n);
        v.push_back(nums[index]);
        subsetsWithoutDup(index+1,nums,v,n);
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        subsetsWithoutDup(0,nums,v,n);
        return res;
    }
};