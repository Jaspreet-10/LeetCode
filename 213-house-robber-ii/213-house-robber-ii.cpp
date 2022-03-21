class Solution {
public:
    //This approach is top down approach because we are checking for every possibility
    // It takes more time as comapre to tbottom up approach i.e, tabulation approach.
    // But it is easy to understand.
    int maxProfit(int index,vector<int>nums,int n,unordered_map<int,int>&memo){
        
        if(index>=n){
            return 0;
        }
        int currentKey = index+1;
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        
        int robbed=nums[index]+maxProfit(index+2,nums,n,memo);
        
        int notRobbed=maxProfit(index+1,nums,n,memo);
        
        memo[currentKey]=max(robbed,notRobbed);
        return memo[currentKey];
    }
    int rob(vector<int>& nums) {
        unordered_map<int,int>memo;
        unordered_map<int,int>memo1;
        int n=nums.size();
        if(n==1)
            return nums[n-1];
        if(n==2)
            return max(nums[0],nums[1]);
        return max(maxProfit(0,nums,n-1,memo),maxProfit(1,nums,n,memo1));  
    }
};