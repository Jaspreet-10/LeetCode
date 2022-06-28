class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int index1=-1,index2=0,N=arr.size();
        for(int i=N-2;i>=0;--i){
            if(arr[i]<arr[i+1]){
                index1=i;
                break;
            }
        }
        if(index1==-1){
            sort(arr.begin(),arr.end());
                return;
        }
        for(int i=N-1;i>=0;--i){
            if(arr[i]>arr[index1]){
                index2=i;
                break;
            }
        }
        swap(arr[index1],arr[index2]);
        sort(arr.begin()+index1+1,arr.end());
        return;
    }
};