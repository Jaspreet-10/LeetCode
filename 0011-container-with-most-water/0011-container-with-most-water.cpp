class Solution {
public:
    int maxArea(vector<int>& A) {
        int left = 0, right = A.size()-1,maxarea = 0;
    while(left<right){
        maxarea = max(maxarea,(min(A[right],A[left])*(right-left)));
        if(A[right]<A[left])
            --right;
        else
            ++left;
    }
    return maxarea;
    }
};