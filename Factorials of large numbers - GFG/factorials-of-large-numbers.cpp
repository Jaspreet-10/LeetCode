// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int>v;
        v.push_back(1);
        int c=0,size=1;
        for(int i=2;i<=N;++i){
            for(int j=size-1;j>=0;--j){
                int t=v[j]*i+c;
                v[j]=t%10;
                c=t/10;
            }
            while(c!=0){
                size++;
                v.insert(v.begin(),c%10);
                c/=10;
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends