class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            return false;
        int v=0,c=0;
        for(int i=0;i<arr.size()-1;++i){
            if(arr[i]<arr[i+1] and v==0){
                c=-1;
                continue;
            }else if(arr[i]>arr[i+1]){
                v=-1;
                continue;
            }else
                return false;
        }
        if(v==-1 and c==-1)
        return true;
        return false;
    }
};