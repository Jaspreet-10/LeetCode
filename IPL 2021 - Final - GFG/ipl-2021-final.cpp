// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        int max=0,close=0,open=0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='(')
                open++;
            if(s[i]==')')
            close++;
            if(close==open){
                if((close+open)>max)
                    max=close+open;
            }
            if(close>open){
                open=close=0;
            }
        }
        close=open=0;
        for(int i=s.length()-1;i>=0;--i){
            if(s[i]==')')
                open++;
            if(s[i]=='(')
            close++;
            if(close==open){
                if((close+open)>max){
                    max=close+open;
                }
            }
            if(close>open)
                open=close=0;
        }
        return max;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
  // } Driver Code Ends