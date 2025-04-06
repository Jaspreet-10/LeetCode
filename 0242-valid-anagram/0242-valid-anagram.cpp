class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>tmp(26,0);
        if(s.size()!=t.size()) return false;
        for(int i = 0 ; i < s.size() ; ++i){
            tmp[s[i] - 'a']++;
            tmp[t[i] - 'a']--;
        }
        for(int i = 0 ; i < tmp.size() ; ++i){
            if(tmp[i]!=0) return false;
        }
        return true;
    }
};