// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char,int>mp;
        unordered_map<char,int>ms;
        int matchCount=0,j=0,ans=INT_MAX,v=0;
        string str="";
        for(int i=0;i<p.length();++i){
            mp[p[i]]++;
        }
        int size=mp.size();
        for(int i=0;i<s.length();++i){
            ms[s[i]]++;
            if(ms[s[i]]==mp[s[i]]){
                matchCount++;
                //cout<<s[i]<<" "<<ms[s[i]]<<" "<<mp[s[i]]<<" "<<matchCount<<"\n";
            }
            //cout<<mp.size()<<" "<<size<<"\n";
            if(matchCount==size){
                //cout<<i<<" "<<s[i]<<"\n";
                while(j<s.length() and ms[s[j]]>mp[s[j]]){
                    ms[s[j]]--;
                    j++;
                }
                if(ans>(i-j+1)){
                    ans=i-j+1;
                    v=-1;
                    str=s.substr(j,i-j+1);
                }
            }
        }
        if(v==-1)
        return str;
        return "-1";
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends