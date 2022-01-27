class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         vector<vector<int>>res;
        if(nums.size()<4)
            return res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;++i){
            for(int j=i+1;j<n-2;++j){
                int diff=target-nums[j]-nums[i];
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=nums[left]+nums[right];
                    if(sum<diff)left++;
                    else if(sum>diff) right--;
                    else{
                        vector<int>v(4,0);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[left];
                        v[3]=nums[right];
                        res.push_back(v);
                        while(left<right and v[2]==nums[left])left++;
                        while(left<right and v[3]==nums[right])right--;
                    }
                }
                while(j+1<n and nums[j+1]==nums[j])j++;
            }
            while(i+1<n and nums[i+1]==nums[i])i++;
        }
        return res;
    }
};