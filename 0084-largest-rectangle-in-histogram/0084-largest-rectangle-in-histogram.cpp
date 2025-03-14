class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        stack<int>st;
        vector<int>left(n,0), right(n,0);
        for(int i = 0 ; i < n ; ++i){
            while(!st.empty() and heights[i]<=heights[st.top()]) st.pop();
            if(st.empty()) left[i] = 0;
            else left[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
         for(int i = n-1 ; i >= 0 ; --i){
            while(!st.empty() and heights[i]<=heights[st.top()]) st.pop();
            if(st.empty()) right[i] = n-1;
            else right[i] = st.top()-1;
            st.push(i);
        }
        for(int i = 0 ; i < n ; ++i){
            ans = max(ans,(heights[i] * (right[i] - left[i]+1)));
        }
        return ans;
    }
};