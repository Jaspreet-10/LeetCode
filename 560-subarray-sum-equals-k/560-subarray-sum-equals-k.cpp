class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int count=0,sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            if(sum==k)
                count++;
            if(m[sum-k]>0){
                count+=m[sum-k];//There must be some elements of sum k which are required
                                //to make the current sum.                                 
            }
            m[sum]++;
        }
        return count;
    }
};