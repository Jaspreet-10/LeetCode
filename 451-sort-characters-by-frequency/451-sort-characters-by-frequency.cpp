class Solution {
public:
    string frequencySort(string s) {
        multimap<int,string>m;
        sort(s.begin(),s.end());
        string str="";
        int len=0;
        for(int i=0;i<s.length()-1;++i){
            if(s[i]==s[i+1]){
                str+=s[i];
                len=str.length();
            }else{
                if(len>=1){
                str+=s[i];
                m.insert(pair<int,string>(len,str));
                }
                else{
                    str+=s[i];
                    m.insert(pair<int,string>(0,str));
                }
                len=0;
                str="";
            }
        }
        str+=s[s.length()-1];
        if(str.length()>1){
        m.insert(pair<int,string>(str.length()-1,str));
        }
        else
        m.insert(pair<int,string>(0,str));
        str="";
        for(auto it=m.rbegin();it!=m.rend();it++){
            cout<<it->first<<" "<<it->second<<"\n";
            str+=it->second;
        }
        return str;
    }
};