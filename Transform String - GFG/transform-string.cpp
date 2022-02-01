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
        int p1=A.length()-1,p2=B.length()-1;
        if(p1!=p2) return -1;
        if(A==B) return 0;
        int count=0;
        string A1=A,B1=B;
        sort(A1.begin(),A1.end());
        sort(B1.begin(),B1.end());
        if(A1==B1){
            while(p1>=0){
                if(A[p1]!=B[p2]){
                    count++;
                }else{
                    p2--;
                }
                p1--;
            }
        }else return -1;
        return count;
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