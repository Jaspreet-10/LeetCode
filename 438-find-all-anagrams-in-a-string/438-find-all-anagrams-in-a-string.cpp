class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>phash(26,0);
        vector<int>hash(26,0);
        vector<int>v;
        if(p.length()>s.length())
            return v;
        for(int i=0;i<p.length();++i){
            phash[p[i]-'a']+=1;
        }
        int size=p.length();
        for(int i=0;i<size;++i){
            hash[s[i]-'a']+=1;
        }
        if(hash==phash)
            v.push_back(0);
        for(int i=0;i<s.length()-size;++i){
             hash[s[i]-'a']-=1;
             hash[s[i+size]-'a']+=1;
            if(hash==phash)
                v.push_back(i+1);
        }
        return v;
    }
};