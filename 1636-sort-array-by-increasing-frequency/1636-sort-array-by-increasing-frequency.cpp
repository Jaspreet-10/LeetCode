class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        multimap<int,int>m;
        vector<int>v;
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i = nums.size()-1 ; i > 0 ; --i){
            if(nums[i]==nums[i-1])
                ++cnt;
            else{
                ++cnt;
                m.insert({cnt,nums[i]});
                cnt = 0;
            }
        }
        if(cnt==0)
        m.insert({1,nums[0]});
        else
            m.insert({cnt+1,nums[0]});
        for(auto it:m){
            for(int i = 0;i<it.first;++i){
                v.push_back(it.second);
            }
        }
        return v;
    }
};