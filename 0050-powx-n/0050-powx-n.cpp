class Solution {
public:
    double myPower(double& ans,double x, long long &nn){
    if(nn<=0){
            return ans;
        }
        if(nn%2 == 0){
            x*=x;
            nn/=2;
        }else{
            ans*=x;
            nn-=1;
        }
        myPower(ans,x,nn);
        return ans;
    }
    double myPow(double x, int n) {
        long long nn = n;
        if(nn<0){
            nn*=-1;
        }
        double ans = 1.0;
        myPower(ans,x,nn);
        if (n < 0) ans = (double)(1.0) / (double)(ans);
        return ans;
        return ans;
    }
};