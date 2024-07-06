class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>m;
        while(m[n] == 0){
            int sum = n;
            m[n]++;
            n = 0;
            while(sum>0){
                n+=(sum%10)*(sum%10);
                sum/=10;
            }
        }
        if(n == 1) return true;
        return false;
    }
};