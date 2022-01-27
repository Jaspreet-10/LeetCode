// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    int i=0,j=1,len=s.length(),max=INT_MIN;
	    int arr[len];
	    if(len==0 || len==1){
	        return 0;
	    }
	    arr[0]=0;
	    while(i<len and j<len){
	        if(s[i]!=s[j]){
	            if(i==0){
	            arr[j]=0;
	            j++;
	            }
	            else{
	                i=arr[i-1];
	            }
	        }else{
	            arr[j]=i+1;
	            i++;
	            j++;
	        }
	    }
	    //if(arr[len-1]!=0)
	    return arr[len-1];
	    //return 0;
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends