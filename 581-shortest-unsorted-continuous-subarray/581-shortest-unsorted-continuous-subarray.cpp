class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>dupli = nums;
        sort(dupli.begin(),dupli.end());
        int mini = -1 , maxi = INT_MAX;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(dupli[i]!=nums[i] and mini == -1 ){
                mini = i;
            }
            else if(dupli[i]!=nums[i] and mini!=-1){
                maxi = i;
            }
        }
        if(mini!=-1 and maxi!=INT_MAX)
            return maxi-mini+1;
        if(mini!=-1)
            return 2;
        return 0;
    }
};