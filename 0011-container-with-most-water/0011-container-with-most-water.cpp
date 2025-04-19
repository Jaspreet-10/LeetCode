class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1, maxi = INT_MIN;
        while(left<right){
            maxi = max(maxi, min(height[left],height[right])*(right-left));
            if(height[left]<height[right]) ++left;
            else --right;
        }
        return maxi;
    }
};