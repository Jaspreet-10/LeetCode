class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int longestStreak = 0;
        for(int i = 0 ; i < nums.size() ; ++i)
            s.insert(nums[i]);
        for(int i = 0 ; i < nums.size() ; ++i){
            if(s.find(nums[i]-1)==s.end()){
                int currentStreak = 1;
                int currentNum = nums[i]+1;
                while(s.find(currentNum)!=s.end()){
                    currentStreak+=1;
                    currentNum+=1;
                }
                longestStreak = max(longestStreak,currentStreak);
            }
        }
        return longestStreak;
    }
};