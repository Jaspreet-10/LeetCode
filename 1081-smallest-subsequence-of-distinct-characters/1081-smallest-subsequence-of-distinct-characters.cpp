class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        bool charPresent[26]={false};
        int lastIndexOfCharacters[26]={-1};
        for(int i=0;i<s.length();++i){
          size_t found= s.find_last_of(s[i]);
          lastIndexOfCharacters[s[i]-'a']=found;
        }
        for(int i=0;i<s.length();++i){
            if(st.empty()){
                st.push(s[i]);
                charPresent[s[i]-'a']=true;
            }
            else if((s[i]-'a')<(st.top()-'a') and lastIndexOfCharacters[st.top()-'a']>i and charPresent[s[i]-'a']==false){
                while(!st.empty() and (s[i]-'a')<(st.top()-'a') and             lastIndexOfCharacters[st.top()-'a']>i){
                charPresent[st.top()-'a']=false;
                st.pop();
                }
                st.push(s[i]);
                charPresent[s[i]-'a']=true;
            }
            else{
                if(charPresent[s[i]-'a']==false){
                st.push(s[i]);
                charPresent[s[i]-'a']=true;
                }else continue;
            }
        }
        string str="";
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};