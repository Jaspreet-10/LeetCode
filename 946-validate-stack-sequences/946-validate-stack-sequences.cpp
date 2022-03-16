class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0,len=pushed.size();
        stack<int>st;
        while(i<len||j<len){
            if(i<len){
                st.push(pushed[i]);
                ++i;
            }
            while(!st.empty() and popped[j]==st.top()){
                ++j;
                st.pop();
            }
            if(!st.empty() and popped[j]!=st.top() and i==len)
                return false;
        }
        return true;
    }
};