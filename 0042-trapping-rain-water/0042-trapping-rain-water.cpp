class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), trappedWater = 0;
        vector<int>leftArray(n,0), rightArray(n,0);
        int maxLeft = 0, maxRight = n-1;
        for(int i = 0 ; i < n ; ++i){
            if(height[i]>=height[maxLeft]){
                leftArray[i] = i;
            }
            else{
                leftArray[i] = maxLeft;
            }
            maxLeft = leftArray[i];
        }
        for(int i = n-1 ; i >=0 ; --i){
            if(height[i]>=height[maxRight]){
                rightArray[i] = i;
            }
            else{
                rightArray[i] = maxRight;
            }
            maxRight = rightArray[i];
        }
        for(int i = 0 ; i < n ; ++i){
            trappedWater+=((min(height[leftArray[i]], height[rightArray[i]]) - height[i]));
        }
        return trappedWater;
    }
};