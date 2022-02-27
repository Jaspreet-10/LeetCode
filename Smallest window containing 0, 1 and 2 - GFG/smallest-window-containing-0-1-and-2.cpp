// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        unordered_map<char,int>m;
        int count=0,min=INT_MAX,j=0;
        for(int i=0;i<S.length();++i){
            m[S[i]]++;
            count++;
            while(m.size()>=3 and j<i){
                m[S[j]]--;
                if(m[S[j]]==0){
                    if(count<min)
                        min=count;
                    m.erase(S[j]);
                }
                count--;
                j++;
            }
        }
        if(min==INT_MAX)
            return -1;
        return min;
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
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends