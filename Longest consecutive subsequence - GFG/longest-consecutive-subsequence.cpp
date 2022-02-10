// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      set<int>s;
      int longestStreak=0;
      for(int i=0;i<N;++i){
          s.insert(arr[i]);
      }
      for(int i=0;i<N;++i){
          if(s.find(arr[i]-1)==s.end()){
             int currentStreak=0,num=arr[i];
            while(s.find(num)!=s.end()){
                currentStreak+=1;
                num+=1;
            }
            longestStreak=max(longestStreak,currentStreak);
          }
        }
        return longestStreak;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends