// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str)
    {
        //code here.
        sort(str.begin(),str.end());
        int c=0,sum=0;
        string s="",v="";
        for(int i=0;i<str.length();++i){
            int ch=str[i];
            if(ch>=65 and ch<=90){
                s+=str[i];
            }
            else{
                v=str[i];
                c=stoi(v);
                sum+=c;
                v="";
            }
        }
        str=to_string(sum);
        s+=str;
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends