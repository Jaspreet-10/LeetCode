// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int helper(int nums[],int low,int high,int target){
        int mid=(low+high)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(low>high)
            return -1;
        if(nums[mid]>target){
            return helper(nums,low,mid-1,target);
        }
        else{
            return helper(nums,mid+1,high,target);
        }
       return -1;
    }
    int search(int nums[], int l, int h, int target){
        int i=0,j=h;
        while(nums[i]>nums[j]){
            i++;
        }
        int ans=-1;
        if(nums[i]==target) return i;
        if(target>=nums[i] and target<=nums[j]){
        ans=helper(nums,i,j,target);
        }
        else{
           ans=helper(nums,0,i-1,target);
        }
        return ans;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends