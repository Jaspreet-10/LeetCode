class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        map<string,int>m;
        if(strs.size()==1) return strs[0];
        string ans="",str="";
        for(int i=0;i<strs[0].size();++i){
            str+=strs[0][i];
            m[str]++;
        }
        for(int i=1;i<strs.size();++i){
            if(strs[i]=="") ans="";
            str="";
            int count=0;
            for(int j=0;j<strs[i].size();++j){
                    str=str+strs[i][j];
                    if(m[str]==i){
                     m[str]++;
                     ans=str;
                    count++;
                    }
                    else{
                        if(count==0) ans="";
                        break;
                    }
            }
        }
        // string strf="";
        // int size=strs.size();
        // for(auto it=m.rbegin();it!=m.rend();--it){
        //     if(it->second==strs.size())
        //         strf=it->first;
        //     else
        //         return strf;
        // }
        return ans;
    }
};