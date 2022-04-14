class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>memo;
        memo[0] = 1;
        int prefixSum = 0 , cnt = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            prefixSum+=nums[i];
            if(memo[((prefixSum%k)+k)%k]>0){
                cnt+=memo[((prefixSum%k)+k)%k];
                memo[((prefixSum%k)+k)%k]+=1;
            }
            else
            memo[((prefixSum%k)+k)%k]+=1;
        }
        return cnt;
    }
};