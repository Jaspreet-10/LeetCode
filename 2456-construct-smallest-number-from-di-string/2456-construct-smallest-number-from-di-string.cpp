class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int>st;
        string answer = "";
        for(int i = 0 ; i < pattern.size()+1 ; ++i){
            st.push(i+1);
            while(!st.empty() and pattern[i] == 'I'){
                answer+=to_string(st.top());
                st.pop();
            }
        }
        while(!st.empty()){
            answer+=to_string(st.top());
            st.pop();
        }
        return answer;
    }
};