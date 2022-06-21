// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int row = 0 , maxi = INT_MIN;
	    bool flag = false;
	    for(int i = 0 ; i < n ; ++i){
	        int cnt = 0;
	        for(int j = 0 ; j < m ; ++j){
	            if(arr[i][j]==1){
	                ++cnt;
	                flag = true;
	            }
	        }
	        if(cnt>maxi){
	            maxi = cnt;
	            row = i;
	        }
	    }
	    if(flag == true)
	    return row;
	    return -1;
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends