class Solution {
public:
    int countPrimes(int n) {
    vector<int>v(n,0);
        int count=0;
    for(long long i=2;i<n;++i){
        if(v[i]==0){
        for(long long j=i*i;j<n;j+=i){
            v[j]=1;
            }
        }
    }
        for(long long i=2;i<n;++i){
            if(v[i]==0)
                count++;
        }
        return count;
    }
};