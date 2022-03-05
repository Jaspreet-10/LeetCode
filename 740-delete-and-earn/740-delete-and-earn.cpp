class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int count[10001]={0};
        int incl=0,excl=0;
        for(int i=0;i<nums.size();++i){
            count[nums[i]]+=1;
        }
        for(int i=0;i<10001;++i){
            int ni=excl+i*count[i];
            int nex=max(incl,excl);
            incl=ni;
            excl=nex;
        }
        return max(incl,excl);
    }
};