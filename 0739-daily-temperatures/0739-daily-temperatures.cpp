class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n = temperatures.size();
        vector<int>v(n, 0);
        for(int i = 0 ; i < n ; ++i){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                v[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
};