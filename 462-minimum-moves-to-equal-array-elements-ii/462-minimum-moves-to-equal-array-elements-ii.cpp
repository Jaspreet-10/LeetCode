class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid = nums.size()/2,diff=0;
        for(int i = 0 ; i < mid ; ++i){
            diff+=(nums[mid]-nums[i]); 
        }
        for(int i = mid+1 ; i < nums.size() ; ++i){
            diff+=(nums[i]-nums[mid]); 
        }
        return diff;
    }
};