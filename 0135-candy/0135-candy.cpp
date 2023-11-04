class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), total = 0;
        vector<int>leftArr(n,1), rightArr(n,1);
        for(int i = 1 ; i < n ; ++i){
            if(ratings[i]>ratings[i-1]){
                leftArr[i] = leftArr[i-1]+1;
            }
        }
        for(int i = n-2 ; i >= 0 ; --i){
            if(ratings[i]>ratings[i+1]){
                rightArr[i] = rightArr[i+1]+1;
            }
        }
        for(int i = 0 ; i < n ; ++i){
            total+=max(leftArr[i],rightArr[i]);
        }
        return total;
    }
};