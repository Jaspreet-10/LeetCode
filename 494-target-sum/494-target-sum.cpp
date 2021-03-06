class Solution {
public:
    int totalWays(vector<int>& nums,int index,int target,int n,map<pair<int,int>,int>&memo){
        if(index==n && target==0)
            return 1;
        
        if(index==n && target!=0)
            return 0;
        pair<int,int>currentKey={index,target};
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        
        int posSign=totalWays(nums,index+1,target-nums[index],n,memo);
        int negSign=totalWays(nums,index+1,target+nums[index],n,memo);
        
        memo[currentKey]=posSign+negSign;
        
        return memo[currentKey];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>,int>memo;
        return totalWays(nums,0,target,nums.size(),memo);   
    }
};