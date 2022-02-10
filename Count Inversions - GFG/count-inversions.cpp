// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long count=0;
    void merge(long long A[],int left,int mid,int right){
        long long i = left,j = mid,k = 0;
        long long temp[right-left+1];
        while(i<mid && j<=right){
       if(A[i] <= A[j]){
           temp[k++] = A[i++];
       }else{
           temp[k++] = A[j++];
           count += mid - i;
       }
   }
        while(i<mid){
       temp[k++] = A[i++];
   }
         while(j<=right){
       temp[k++] = A[j++];
   }
   // copy temp array to original array..
   for(int i=left,k=0;i<=right;k++,i++){
       A[i] = temp[k];
   }
    }
    
    void mergeSort(long long arr[],int l,int r){
        if(l<r){
            long long mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid+1,r);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends