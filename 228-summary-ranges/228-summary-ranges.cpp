class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>v;
         if(nums.size()==0)
            return v;
        int s=nums[0],index=0,i=0;
        for(i=0;i<nums.size()-1;++i){
            if(nums[i]+1!=nums[i+1] and i-index>=1){
                string res=to_string(s)+"->"+to_string(nums[i]);
                v.push_back(res);
                s=nums[i+1];
                index=i+1;
            }
            else if(nums[i]+1!=nums[i+1] and i-index<1){
                string res=to_string(s);
                v.push_back(res);
                s=nums[i+1];
                index=i+1;
            }
        }
        if(i-index>=1){
            string res=to_string(s)+"->"+to_string(nums[i]);
            v.push_back(res);
        }else{
            string res=to_string(nums[i]);
            v.push_back(res);
        }
        return v;
    }
};