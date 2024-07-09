class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int leftSmallest[n], rightSmallest[n], maxi = INT_MIN;
        stack<int>st;
        for(int i = 0 ; i < n ; ++i){
            while(!st.empty() and heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()){
                leftSmallest[i] = st.top()+1;
            }else{
                leftSmallest[i] = 0;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;--i){
            while(!st.empty() and heights[st.top()]>heights[i]) st.pop();
            if(!st.empty()){
                rightSmallest[i] = st.top()-1;
            }else{
                rightSmallest[i] = n-1;
            }
            st.push(i);
        }
        int maxA = 0;
        for(int i = 0 ; i < n ; ++i){
            cout<<heights[i]*(rightSmallest[i]-leftSmallest[i]+1)<<" ";
            maxA = max(maxA,heights[i]*(rightSmallest[i]-leftSmallest[i]+1));
        }
        return maxA;
    }
};