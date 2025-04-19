class Solution {
public:
    int trap(vector<int>& height) {
        int maxi = 0, n = height.size(), answer = 0;
        vector<int>left(n,0), right(n, 0);
        for(int i = 0 ; i < n ; ++i){
            if(height[i]>=height[maxi]){
                left[i] = i;
            }else{
                left[i] = maxi;
            }
            maxi = left[i];
        }
        maxi = n-1;
        for(int i = n-1 ; i>=0 ; --i){
            if(height[i]>=height[maxi]){
                right[i] = i;
            }else{
                right[i] = maxi;
            }
            maxi = right[i];
        }
        for(int i = 0 ; i < n ; ++i){
            answer+=(min(height[right[i]], height[left[i]])-height[i]);
        }
        return answer;
    }
};