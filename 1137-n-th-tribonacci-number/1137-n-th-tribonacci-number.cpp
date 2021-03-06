class Solution {
public:
    unordered_map<int,int>memo;
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        int currentKey=n;
        if(memo.find(currentKey)!=memo.end())
            return memo[currentKey];
        memo[currentKey]=tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
        return memo[currentKey];
    }
};