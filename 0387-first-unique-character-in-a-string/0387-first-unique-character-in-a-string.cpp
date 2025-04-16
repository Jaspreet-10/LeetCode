class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m;
        int maxi = INT_MAX;
        for(int i = 0 ; i < s.size() ; ++i){
            if(m.find(s[i])!=m.end()){
                m[s[i]] = -1;
            }else
             m[s[i]] = i+1;
        }

        for(auto it:m){
            cout<<it.first<<" "<<it.second<<"\n";
            if(it.second!=-1 && it.second<maxi){
                maxi = it.second;
            }
        }
        if(maxi == INT_MAX) return -1;
        return maxi-1;
    }
};