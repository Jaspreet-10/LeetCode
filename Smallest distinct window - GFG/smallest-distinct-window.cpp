// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        unordered_map<char,int>m,mp;
        int len=str.length();
        for(int i=0;i<len;++i){
            m[str[i]]++;
        }
        int size=m.size(),j=0,start=0,end=0,min=INT_MAX;
        for(int i=0;i<len;++i){
            mp[str[i]]++;
            if(mp.size()==size){
                while(mp.size()==size){
                    if(mp[str[j]]>1)
                    mp[str[j]]--;
                    else
                    break;
                    ++j;
                }
                if(i-j<min){
                start=j;
                end=i;
                min=i-j;
                }
            }
        }
        string s="";
        for(int i=start;i<=end;++i){
            s+=str[i];
        }
        return s;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends