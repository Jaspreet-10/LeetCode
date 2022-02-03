// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int> >res;
        map<vector<int>,int>m;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-3;++i){
            for(int j=i+1;j<n-2;++j){
                int left=j+1,right=n-1;
                while(left<right){
                    int sum=arr[i]+arr[j]+arr[left]+arr[right];
                    if(sum<k)
                    left++;
                    else if(sum>k)
                    right--;
                    else{
                        vector<int>v={arr[i],arr[j],arr[left],arr[right]};
                        left++;
                        right--;
                        if(m[v]==0){
                         res.push_back(v);
                         m[v]++;
                        }
                    }
                }
            }
        }
      return  res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends