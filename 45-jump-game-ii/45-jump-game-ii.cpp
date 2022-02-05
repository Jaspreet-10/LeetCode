class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi=nums[0],step=nums[0],jump=1,n=nums.size();
        if(n==1) return 0;
        for(int i=1;i<n;++i){
            step--;
            if(i==n-1){
                return jump;
            }
            maxi=max(maxi,nums[i]+i);
            if(step==0){
                jump++;
                step=maxi-i;
                maxi=0;
            }
        }
        return 0;
    }
};