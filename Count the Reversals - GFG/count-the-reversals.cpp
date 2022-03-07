// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends
int countRev (string s)
{
    stack<char>st;
    int count=0;
    if(s.length()%2!=0)
        return -1;
        int op=0,cl=0;
    for(int i=0;i<s.length();++i){
        if(!st.empty() and s[i]=='}' and st.top()=='{'){
            --op;
            st.pop();
        }
        else if(s[i]=='{'){
            st.push(s[i]);
            ++op;
        }
        else{
            ++cl;
        }
    }
    if(op%2==0){
        count+=op/2;
    }else{
        count+=(op/2)+1;
    }
    if(cl%2==0){
        count+=cl/2;
    }else{
        count+=(cl/2)+1;
    }
    return count;
}