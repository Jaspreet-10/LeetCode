class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<int>st;
        for(int i = 0 ; i < heights.size() ; ++i){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) left[i] = 0;
            else left[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        for(int i = n-1 ; i >= 0 ; --i){
            while(!st.empty() && heights[st.top()]>heights[i]) st.pop();
            if(st.empty()) right[i] = n-1;
            else right[i] = st.top()-1;
            st.push(i);
        }
        int maxLen = 0;
        for(int i = 0 ; i < n ; ++i){
            maxLen = max(maxLen,(right[i] - left[i] + 1)*heights[i]);
        }
        return maxLen;
    }
};