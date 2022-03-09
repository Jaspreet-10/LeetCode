// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        string str="";
        stack<char>st;
        for(int i=0;i<s.length();++i){
            if(s[i]!='.'){
                st.push(s[i]);
            }else{
                while(!st.empty()){
                    str+=st.top();
                    st.pop();
                }
                str+='.';
            }
        }
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        return str;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends