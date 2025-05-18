class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       if(strs.size() == 1)
            return strs[0];
        sort(strs.begin(),strs.end());
        string start = strs[0], last = strs[strs.size()-1], ans = "";
        for(int i = 0 ; i < min(start.length(),last.length()) ; ++i){
            if(start[i]!=last[i])
                return ans;
            ans+=start[i];
        }
        if(ans!="")
            return ans;
        return "";
    }
};