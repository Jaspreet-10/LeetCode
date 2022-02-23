class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        int count=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0){
                m.insert(pair<int,vector<int> >(nums[i], vector<int>()));
                m[nums[i]].push_back(i);
            }else{
                for(int j=0;j<m[nums[i]].size();++j){
                    count++;
                }
                m[nums[i]].push_back(i);
            }
        }
        return count;
    }
};