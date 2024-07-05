class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;
        string str = "";
        vector<int>v;
        for(int i = s.size()-1 ; i >= 0 ; --i){
           if(m[s[i]] == 0)
            m[s[i]] = i+1; 
        }
        int maxi = m[s[0]];
        for(int i = 0 ; i < s.size() ; ++i){
            if(m[s[i]]>maxi) maxi = m[s[i]];
            str+=s[i];
            // cout<<str<<"\n";
            if(maxi-1 == i){ 
            maxi = INT_MIN;
            v.push_back(str.length());
            str = "";
            }
        }
        return v;
    }
};