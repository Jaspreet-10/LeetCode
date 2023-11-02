class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=nums[0],step=nums[0],jump=1,n=nums.size();
        if(n==1)
            return true;
        if(n>=1 and nums[0]==0)
            return false;
        for(int i=1;i<n;++i){
            step--;
            if(i==n-1){
                return true;
            }
            maxi=max(maxi,nums[i]+i);
            if(step==0){
                jump++;
                if(i>=maxi)
                    return false;
                step=maxi-i;
                maxi=0;
            }
        }
        return false;
    }
};