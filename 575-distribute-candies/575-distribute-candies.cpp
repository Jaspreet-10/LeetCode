class Solution {
public:
    int distributeCandies(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;++i){
            m[nums[i]]++;
        }
        if(m.size()>=n/2)
            return n/2;
        return m.size();
    }
};