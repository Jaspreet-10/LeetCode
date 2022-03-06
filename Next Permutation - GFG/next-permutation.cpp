// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int index1=-1,index2=0;
        for(int i=N-2;i>=0;--i){
            if(arr[i]<arr[i+1]){
                index1=i;
                break;
            }
        }
        if(index1==-1){
            sort(arr.begin(),arr.end());
                return arr;
        }
        for(int i=N-1;i>=0;--i){
            if(arr[i]>arr[index1]){
                index2=i;
                break;
            }
        }
        swap(arr[index1],arr[index2]);
        sort(arr.begin()+index1+1,arr.end());
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends