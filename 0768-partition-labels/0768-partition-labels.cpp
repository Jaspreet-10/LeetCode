class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;
        vector<int>v;
        int j = 0, count = 0;
        for(int i = s.size()-1;i>=0;--i){
           if(m[s[i]] == 0)
            m[s[i]] = i+1;
        }
        int index = m[s[0]];
        while(j<s.size()){
            index = max(index,m[s[j]]); 
            ++count;
            if(index-1 == j){
                index = INT_MIN;
                v.push_back(count);
                count = 0;
            }  
            ++j;
        }
        return v;
    }
};