class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(int i = 0 ; i < num.size() ; ++i){
            int dig = num[i]-'0';
            while(!st.empty() && st.top()>dig && k>0){
                cout<<k<<" "<<st.top()<<" ";
                st.pop();
                --k;
            }
            if(st.empty() && dig==0)continue;
            st.push(dig);
        }
        while(k>0 && !st.empty()){
            st.pop();
            --k;
        }
        string res = "";
        while(!st.empty()){
            res+=to_string(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res == "" ? "0" : res;
    }
};