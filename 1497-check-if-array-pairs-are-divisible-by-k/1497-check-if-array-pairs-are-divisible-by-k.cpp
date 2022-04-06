class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int res[k];
            for(int i=0;i<k;++i)
                res[i] = 0;
        for(int i=0;i<arr.size();++i){
            int currentRem = ((arr[i]%k)+k)%k;
            res[currentRem]+=1;
        }
        
        for(int i = 0 ; i<=k/2 ; ++i){
            if(i==0){
            if(res[i]%2!=0)
                return false;
            }
            else{
                int y = k-i;
                if(res[y]!=res[i])
                    return false;
            }
        }
        return true;
    }
};