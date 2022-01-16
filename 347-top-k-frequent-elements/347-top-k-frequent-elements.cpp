class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        vector<pair<int,int>>v;
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n-1;++i){
            if(nums[i]==nums[i+1]){
                count++;
            }else{
                v.emplace_back(count,nums[i]);
                count=0;
            }
        }
        v.emplace_back(count,nums[n-1]);
        sort(v.begin(),v.end());
        for(auto it=v.rbegin();it!=v.rend();++it)
        {
            if(k>0){
                ans.push_back(it->second);
                k--;
            }else break;
            cout<<it->first<<" "<<it->second<<"\n";
        }
        return ans;
    }
};