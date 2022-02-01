class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        if(n==1||n==4) return true;
        long long int ans=4;
        while(true){
            ans*=4;
            if(ans>n)
                return false;
            if(ans==n) return true;
        }
        return true;
    }
};