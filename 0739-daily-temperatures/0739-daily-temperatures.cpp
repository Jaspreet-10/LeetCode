class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        if(n == 0) return {};
        vector<int>ans(n,0);
        stack<int>st;
        st.push(0);
        for(int i = 0 ; i < n ; ++i){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                 ans[st.top()] = i - st.top();
                 st.pop();
            } 
             st.push(i);
        }
        return ans;
    }
};