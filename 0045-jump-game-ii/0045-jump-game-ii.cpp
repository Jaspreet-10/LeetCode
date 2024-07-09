class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, reachable = 0, current = 0;
        for(int i = 0 ; i < nums.size()-1 ; ++i){
            reachable = max(reachable, nums[i]+i);
            if(i>reachable) return -1;
            if(i==current){
                current = reachable;
                ++jumps;
            }
        }
        return jumps;
    }
};