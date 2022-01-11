class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int sum=0,count=0,n=nums.size();
        for(int i=0;i<n;++i){
            sum+=nums[i];
            if(sum==k) count++;
            if(m[sum-k]) count+=m[sum-k];
            m[sum]++;
        }
        return count;
    }
};