class Solution {
public:
bool equalSubset(int target,int index,vector<int>nums,map<pair<int,int>,bool>&memo,int n){
        if(index>=n)
            return false;
        
        pair<int,int>currentKey={index+1,target};
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        bool oneSubset=false;
        if(target>=nums[index])
        oneSubset=equalSubset(target-nums[index],index+1,nums,memo,n);
        if(oneSubset==true)
            return true;
        bool secondSubset=equalSubset(target,index+1,nums,memo,n);
        if(secondSubset==true)
            return true;
        if(target==0)
            return true;
        memo[currentKey]=(oneSubset or secondSubset);
        return memo[currentKey];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
       map<pair<int,int>,bool>memo;
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        return equalSubset(target,0,nums,memo,n);
    }
};