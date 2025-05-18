class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string, int>m;
        string ans = "";
        int maxi = 0;
        for(int i = 0 ; i < strs.size() ; ++i){
            string str = "";
            for(int j = 0 ; j < strs[i].size() ; ++j){
                str+=strs[i][j];
                if(i>0 and m[str] == 0) break;
                m[str]++;
            }
        }
        for(auto it:m){
            if(it.second == strs.size() && it.first.size()>maxi){
                ans = it.first;
                maxi = it.first.size();
            }
        }
        return ans;
    }
};