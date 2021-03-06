class Solution {
public:
    int maxProfit(int index,vector<int>nums,int n,unordered_map<int,int>&memo){
        if(index>=n) 
            return 0;
        int currentKey=index;
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        int oneJump=nums[index]+maxProfit(index+2,nums,n,memo);
        int twoJumps=maxProfit(index+1,nums,n,memo);
        
        memo[currentKey]=max(oneJump,twoJumps);
        return memo[currentKey];
    }
    int rob(vector<int>& nums) {
        unordered_map<int,int>memo;
        return maxProfit(0,nums,nums.size(),memo);    
    }
};