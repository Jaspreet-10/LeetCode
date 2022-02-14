// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        sort(arr,arr+n);
        int max=n,min=n,count=1,s=0;
        for(int i=0;i<n;i++){
            if(count!=arr[i] and s==0){
                min=count;
                //cout<<count<<" "<<arr[i];
                s=-1;
            }
            if(arr[i]==arr[i+1] and i!=n-1)
                {
                    max=arr[i];
                    //count++;
                    i++;
                }
                count++;
        }
        arr[0]=max;
        arr[1]=min;
        return arr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends