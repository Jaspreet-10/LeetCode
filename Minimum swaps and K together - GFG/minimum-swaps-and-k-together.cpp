// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int good_value=0 , bad_value = 0;
        for(int i=0;i<n;++i){
            if(arr[i]<=k)
                ++good_value;
        }
        // if(good_value == n || good_value == 0)
        //     return 0;
        for(int i = 0 ; i < good_value ; ++i){
            if(arr[i]>k)
                ++bad_value;
        }
        int mini = bad_value;
        for(int i = 0 ; i <n-good_value ; ++i){
            if(arr[i+good_value]>k)
                ++bad_value;
            if(arr[i]>k)
             --bad_value;
             mini = min(mini,bad_value);
        }
        return mini;
    }
};


// { Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}
  // } Driver Code Ends