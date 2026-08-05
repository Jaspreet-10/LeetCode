class Solution {
public:
    vector<int> partitionLabels(string s) {
        int counter = 0, j = 0;
        vector<int>ans;
        unordered_map<char, int>m;
        for(int i = 0 ; i < s.size() ; ++i){
            m[s[i]] = i;
            // cout<<s[i]<<" "<<m[s[i]]<<"\n";
        }
        int start = m[s[0]];
        for(int i = 0 ; i < s.size() ; ++i){
            start = max(start, m[s[i]]);
            counter++;
            if(start==i){
                ans.push_back(counter);
                start = m[s[i+1]];
                counter = 0;
            }
        }
        return ans;
    }
};