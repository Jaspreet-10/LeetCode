// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        if(N==1)
            return arr[0];
        string s="";
        map<string,int>m;
        string str=arr[0];
        for(int i=0;i<str.length();++i){
            s+=str[i];
            m[s]++;
        }
        int v=0,len=0;
        string LCP="";
        for(int i=1;i<N;++i){
            s="";
            string str=arr[i];
            for(int j=0;j<str.length();++j){
                s=s+str[j];
                if(m[s] and m[s]==i){
                v=-1;
                LCP=s;
                m[s]++;
                len=m[s];
                }
                else break;
            }
        }
        if(v==-1 and len==N)
        return LCP;
        return "-1";
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends