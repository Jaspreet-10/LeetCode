// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        int lenA=A.length(),lenB=B.length();
        if(lenA!=lenB)
            return -1;
            int cnt=0;
        string A1=A, B1=B;
        sort(A1.begin(),A1.end());
        sort(B1.begin(),B1.end());
        if(A1==B1){
        while(lenA>=0){
            if(A[lenA]!=B[lenB]){
                ++cnt;
            }else 
            --lenB;
            --lenA;
        }
        }else return -1;
        return cnt;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends