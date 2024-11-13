class Solution {
public:
    bool isAnagram(string s, string t) {
         vector<int>hashArray(26,0);
        if(s.length()!=t.length()) return false;
        for(int i = 0 ; i < s.length() ; ++i){
            hashArray[s[i]-'a']++;
            hashArray[t[i]-'a']--;
        }
        for(int i = 0 ; i < 26 ; ++i){
            if(hashArray[i]!=0) return false; 
        }
        return true;
    }
};