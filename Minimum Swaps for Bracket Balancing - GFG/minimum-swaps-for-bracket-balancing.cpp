// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
         stack<char>s;
         int open=0,close=0,ans=0,fault=0;
         for(int i=0;i<S.length();++i){
             if(S[i]==']'){
                 close++;
                 fault=close-open;
             }else{
                 ++open;
                 if(fault>=1)
                    ans+=fault;
                    fault--;
             }
         }
         return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends