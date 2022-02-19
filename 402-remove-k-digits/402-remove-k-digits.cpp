class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        if(num.length()==k)
            return "0";
        for(int i=0;i<num.length();++i){
            while(!s.empty() and s.top()>num[i] and k>0){
            k--;
            s.pop();
            }
            if(s.empty()){
                if(num[i]!='0')
                    s.push(num[i]);
            }
            else
            s.push(num[i]);
        }
        while(k!=0 and !s.empty()){
            s.pop();
            k--;
        }
        string str="";
        while(!s.empty()){
        str+=s.top();
        s.pop();
        }
        if(str=="")
            return "0";
        reverse(str.begin(),str.end());
        return str;
    }
};



// 