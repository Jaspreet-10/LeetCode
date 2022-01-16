class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return 0;
        while(n>1 and (n&1)==0)
            n>>=1;
        return n==1?true:false;
    }
};