// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void printPermutations(string S,vector<char>ds,vector<string>&res,
	    bool freq[],int n){
	        if(n==ds.size()){
	            string str="";
	            for(auto it:ds){
	                str+=it;
	            }
	            res.push_back(str);
	            return ;
	        }
	        for(int i=0;i<n;++i){
	            if(!freq[i]){
	            freq[i]=1;
	            ds.push_back(S[i]);
	            printPermutations(S,ds,res,freq,n);
	            ds.pop_back();
	            freq[i]=0;
	            }
	        }
	        return;
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string>res;
		    vector<char>ds;
		    int n=S.length();
		    bool freq[n-1]={0};
		    printPermutations(S,ds,res,freq,n);
		    sort(res.begin(),res.end());
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends