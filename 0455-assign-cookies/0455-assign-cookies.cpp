class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
            sort(g.begin(),g.end());
            sort(s.begin(),s.end());
            int j = 0, count = 0;
            for(int i = 0 ; i < g.size() ; ++i){
                while(i<g.size() and j<s.size()){
                    if(g[i]<=s[j]){
                        ++count;
                        ++i;
                    }
                    ++j;
                }
            }
            return count;
        }
};