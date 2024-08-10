class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>m;
        string ans = "";
        for(int i = 0 ; i < s.length() ; ++i) m[s[i]]++;
        for(int i = 0 ; i < order.length() ; ++i){
            for(int j = 0 ; j < m[order[i]] ; ++j){
                ans+=order[i];
            }
            m[order[i]] = 0;
        }
        for(int i = 0 ; i < s.length() ; ++i){
            if(m[s[i]]>0) ans+=s[i];
        }
        return ans;
    }
};