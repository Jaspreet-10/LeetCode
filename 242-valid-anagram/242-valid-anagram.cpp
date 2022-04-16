class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m;
        if(t.length()>s.length())
            return false;
        for(int i = 0 ; i < s.length() ; ++i){
            m[s[i]]++;
        }
         for(int i = 0 ; i < s.length() ; ++i){
            m[t[i]]--;
            if(m[t[i]]==0)
                m.erase(t[i]);
        }
        if(m.size()==0)
            return true;
        return false;
    }
};