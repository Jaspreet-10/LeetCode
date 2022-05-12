class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>m;
        int count=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                count+=m[nums[i]];
                m[nums[i]]++;
            }else{
                m[nums[i]]++;
            }    
        }
        return count;
    }
};