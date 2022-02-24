// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> primeDivision(int N){
        vector<int>v;
        for(int i=2;i<=N;++i){
            int v1=0;
            for(int j=2;j<=sqrt(i);++j){
                if(i%j==0){
                    v1=-1;
                    break;
                }
            }
            if(v1==0){
                //cout<<i<<" ";
                v.push_back(i);
                }
        }
        for(int i=0;i<v.size();i++){
            int k=N-v[i];
            auto it=find(v.begin(),v.end(),k);
            if(it!=v.end()){
                v.clear();
                v.push_back(v[i]);
                v.push_back(k);
                return v;
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends