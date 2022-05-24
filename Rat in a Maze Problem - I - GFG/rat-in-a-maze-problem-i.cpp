// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void findTotalPaths(vector<vector<int>> &m,int r,int c,int row,
    int col,string s,vector<string>&ans){
        if(r<0 || c<0 || r>=row || c>=col || m[r][c]<=0)
            return ;
        if(r==row-1 and c==col-1){
            ans.push_back(s);
            return;
        }
            m[r][c]=-1;
            findTotalPaths(m,r+1,c,row,col,s+"D",ans);
            findTotalPaths(m,r,c-1,row,col,s+"L",ans);
            findTotalPaths(m,r,c+1,row,col,s+"R",ans);
            findTotalPaths(m,r-1,c,row,col,s+"U",ans);
            m[r][c]=1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        findTotalPaths(m,0,0,m[0].size(),n,"",ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends