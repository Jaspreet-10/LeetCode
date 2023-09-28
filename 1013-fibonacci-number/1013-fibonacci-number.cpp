class Solution {
public:
    unordered_map<int,int>m;
    int calculateFib(int n){
        if(n == 0) 
            return 0;
        if(n == 1)
            return 1;
        if(m[n]!=0)
            return m[n];
        int ans = calculateFib(n-1) + calculateFib(n-2);
        m[n] = ans;
        return ans;
    }
    int fib(int n) {
        return calculateFib(n);
    }
};