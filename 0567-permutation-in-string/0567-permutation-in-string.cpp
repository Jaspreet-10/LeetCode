class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m;
        int i = 0, j = 0, n1 = s1.length(), n2 = s2.length();
        for(int i = 0 ; i < n1 ; ++i) m[s1[i]]++;
        while(i<n2){
            m[s2[i]]--;
            if(m[s2[i]] == 0) m.erase(s2[i]);
            if(i-j+1 == n1){
                // cout<<s2.substr(j, i-j+1)<<"\n";
                if(m.size() == 0) return true;
                m[s2[j]]++;
                if(m[s2[j]] == 0) m.erase(s2[j]);
                ++j;
            }
            ++i;
        }
        return false;
    }
};