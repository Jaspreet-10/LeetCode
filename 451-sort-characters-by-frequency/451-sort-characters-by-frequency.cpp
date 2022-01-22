class Solution {
public:
    string frequencySort(string s) {
        multimap<int,string>m;
        sort(s.begin(),s.end());
        string str="";
        int len=0 , n=s.length();
        for(int i=0;i<n;++i){
            if(i!=n-1 and s[i]==s[i+1]){
                str+=s[i];
                len=str.length();
            }else{
                str+=s[i];
                m.insert(pair<int,string>(len,str));
                len=0;
                str="";
            }
        }
            for(auto it=m.rbegin();it!=m.rend();it++){
            str+=it->second;
        }
        return str;
    }
};