class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int longestStreak = 0;
        for(int i = 0 ; i <nums.size() ; ++i){
            s.insert(nums[i]);
        }
        for(int i = 0 ; i < nums.size() ; ++i){
            int streak = 1;
            if(s.find(nums[i]-1)==s.end()){
                int number = nums[i]+1;
                while(s.find(number)!=s.end()){
                    ++streak;
                    ++number;
                }
            }
            longestStreak = max(longestStreak, streak);
        }
        return longestStreak;
    }
};