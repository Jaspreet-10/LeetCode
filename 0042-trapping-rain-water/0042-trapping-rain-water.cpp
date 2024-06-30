class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left[n],right[n], maxi = INT_MIN;
        int trappedWater = 0;
        
        for(int i = 0 ; i < n ; ++i){
            left[i] = max(arr[i],maxi);
            maxi = left[i];
        }
        maxi = INT_MIN;
        
        for(int i = n-1 ; i >= 0 ; --i){
            right[i] = max(arr[i],maxi);
            maxi = right[i];
        }
        for(int i = 0 ; i < n ; ++i){
            if(left[i]<right[i]){
                trappedWater+= (left[i]-arr[i]);
            }
            else
            trappedWater+= (right[i]-arr[i]);
        }
        return trappedWater;
    }
};