// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        unordered_map<int,int>m;
        vector<int>v;
        for(int i = 0 ; i < n ; ++i){
            if(m[arr[i]]==0)
                m[arr[i]]++;
            else if(m[arr[i]]>0 and m[arr[i]]!=-1){
                v.push_back(arr[i]);
                m[arr[i]]=-1;
            }
        }
        if(v.size()==0)
            return v = {-1};
        sort(v.begin(),v.end());
        return v;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends