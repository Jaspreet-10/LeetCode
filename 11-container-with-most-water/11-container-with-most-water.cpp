class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),i=0,j=n-1,m=0,max=INT_MIN;
        while(i<j){
            m=(j-i)*min(height[i],height[j]);
            if(m>max)
                max=m;
            if(height[i]>height[j]){
                j--;
            }else{
                i++;
            }
        }
        return max;
    }
};