class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int n=s.length(),i=0;
        for(i=0;i<n;++i){
            if(m[s[i]]==0)
                m[s[i]]++;
            else{
                m[s[i]]++;
                break;
            }
        }
        int maxi=m.size(),j=0;
        while(i<n){
                while(m[s[i]]>1 and j<i){
                    cout<<j<<" "<<s[j]<<" "<<m[s[j]]<<"\n";
                    m[s[j]]--;
                    ++j;
                }
                if(i-j+1>maxi)
                maxi=i-j+1;
                ++i;
                m[s[i]]++;
        }
        return maxi;
    }
};