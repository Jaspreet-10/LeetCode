class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>v1(26,0),v2(26,0);
        int i = 0, j = 0;
        for(int i = 0 ; i < s1.length() ; ++i) v1[s1[i]-'a']++;
        while(i<s2.length()){
            while(i-j>=s1.length()){
                v2[s2[j]-'a']--;
                ++j;
            }
            // cout<<s2.substr(j,i-j+1)<<"\n";
            v2[s2[i]-'a']++;
            if(v1 == v2) return true;
            ++i;
        }
        return false;
    }
};