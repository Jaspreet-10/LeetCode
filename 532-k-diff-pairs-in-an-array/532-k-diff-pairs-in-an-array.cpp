class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int>m;
        // map<pair<int,int>,int>dupli;
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();++i){
            int diff=nums[i]-k;
            if(m[diff]>0 and m[diff]!=-1){
                count++;
                m[diff]=-1;
                if(diff!=nums[i])
                m[nums[i]]++;
            }else{
                if(m[nums[i]]!=-1)
                m[nums[i]]++;
            }
        }
        return count;
    }
};