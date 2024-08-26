class Solution {
public:
    int jump(vector<int>& nums) {
        int r = 0, c = 0, jumps = 0;
        for(int i = 0 ; i < nums.size()-1 ; ++i){
            if(i>c) return -1;
            r = max(r, nums[i]+i);
            if(i == c){
                c = r;
                ++jumps;
            }
        }
        return jumps;
    }
};