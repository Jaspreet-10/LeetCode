// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
        map<char,int>a1,b1;
    	int p1=A.length()-1,p2=B.length()-1;
        if(p1!=p2) return -1;
        if(A==B) return 0;
        int count=0;
            while(p1>=0){
                if(A[p1]!=B[p2]){
                    count++;
                }else{
                    p2--;
                }
                a1[A[p1]]+=1;
                b1[B[p1]]+=1;
                p1--;
            }
        if(a1==b1)
        return count;
        return -1;
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
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends