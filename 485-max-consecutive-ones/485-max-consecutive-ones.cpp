class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxi = 0 , count = 0 , sum = 0;
        m[0] = 1;
        for(int i = 0 ; i  < nums.size() ; ++i){
            sum+=nums[i];
            if(m[sum]>0){
                maxi = max(maxi,count);
                count=0;
            }else{
                ++count;
                m[sum]++;
            }
        }
        maxi = max(maxi,count);
        return maxi;
    }
};