// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        multimap<int,int>m;
        for(int i=n-1;i>=0;--i){
            int count=__builtin_popcount(arr[i]);
            m.insert(make_pair(count,arr[i]));
        }
        int i=0;
        for(auto it=m.begin();it!=m.end();++it){
            arr[n-i-1]=it->second;
            i++;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends