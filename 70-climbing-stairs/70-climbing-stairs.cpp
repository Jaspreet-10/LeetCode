class Solution {
public:
    int totalWays(int currentStairs,int targetStairs,unordered_map<int,int>&memo){
        if(currentStairs==targetStairs)
            return 1;
        
        if(currentStairs>targetStairs)
            return 0;
        
        int currentKey=currentStairs;
        
        if(memo[currentKey]>0)
            return memo[currentKey];
        
        int oneJump=totalWays(currentStairs+1,targetStairs,memo);
        
        int twoJumps=totalWays(currentStairs+2,targetStairs,memo);
        
        memo[currentKey]=oneJump+twoJumps;
        
        return oneJump+twoJumps;
    }
        
    int climbStairs(int n) {
        unordered_map<int,int>memo;
        return totalWays(0,n,memo);
    }
};