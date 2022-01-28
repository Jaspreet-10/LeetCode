// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        int res=0;
        unordered_map<char,int>mp{{'I',1},{'V',5},{'X',10},{'L',50},
        {'C',100},{'D',500},{'M',1000}};
        int i=0;
            for(i  = 0  ; i < s.length()-1; i++){
            if(mp[s[i]] >= mp[s[i + 1]]){
                res += mp[s[i]];
            }    
            else { 
                res -= mp[s[i]]; 
            }
        }
        if(i == s.length()-1)
            {
                res += mp[s[i]];
                
            }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends