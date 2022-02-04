class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        int sum=0,maxLen=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0)
                sum+=-1;
            else
                sum+=1;
            if(sum==0){
                maxLen=i+1;
            }
            if(m[sum]>0){
                maxLen=max(maxLen,i+1-m[sum]);
            }else{
                m[sum]=i+1;
            }
        }
        return maxLen;
    }
};