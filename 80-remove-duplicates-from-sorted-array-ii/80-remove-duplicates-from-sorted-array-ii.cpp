class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==2) return n;
        for(int i=2;i<n;++i){
            int j=i;
            while(i<n and nums[j-2]==nums[i]){
                nums.erase(nums.begin()+i);
                n--;
            }
        }
        return nums.size();
    }
};