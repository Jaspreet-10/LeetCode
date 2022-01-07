// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    int table[n+1][n+1];
		    int maxi=0;
		    memset(table,0,sizeof(table));
		    for(int i=1;i<n+1;i++){
		        for(int j=i;j<n+1;j++){
		            if(i!=j and str[i-1]==str[j-1]){
		                table[i][j]=1+table[i-1][j-1];
		            }else{
		                table[i][j]=max(table[i-1][j],table[i][j-1]);
		                //maxi=max(maxi,table[i][j]);
		            }
		        }
		    }
		    return table[n][n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends