// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends


int maximumSum( int n,int m, vector<vector<int>> &a) {
    
    int sum=0,min=INT_MAX,count=a.size()-1;
    for(int i=a.size()-1;i>=0;--i){
        int max=INT_MIN;
        for(int j=0;j<a[i].size();++j){
            if(a[i][j]>max and a[i][j]<min){
                max=a[i][j];
                if(count==i)
                count--;
            }
        }
        min=max;
        sum+=max;
    }
    if(count==-1)
    return sum;
    return 0;
}