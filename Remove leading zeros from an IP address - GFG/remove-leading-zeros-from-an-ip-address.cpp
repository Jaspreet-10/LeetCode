// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        string res="",str="";
        int v=0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='.'){
                while(str[0]=='0' and str.length()>1)
                    str.erase(0,1);
                v=-1;
            }
            if(v==-1){
                res+=str+'.';
                str="";
                v=0;
            }else
            str+=s[i];
        }
        while(str[0]=='0' and str.length()>1){
            str.erase(0,1);
        }
        res+=str;
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends