class Solution {
public:
    bool isIsomorphic(string str1, string str2) {
        if(str1.length()!=str2.length())
            return false;
        unordered_map<char,char>m1,m2;
        for(int i=0;i<str1.length();++i){
            if((m1.count(str1[i])==0) and (m2.count(str2[i])==0)){
            m1[str1[i]]=str2[i];
            m2[str2[i]]=str1[i];
            }
            else{
                if(m1[str1[i]]!=str2[i] || m2[str2[i]]!=str1[i])
                    return false;
                else
                    continue;
            }
        }
        return true;

    }
};