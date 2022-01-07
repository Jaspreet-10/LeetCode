// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string>v;
	    string Swap(string s,int l,int i){
	        swap(s[l],s[i]);
	        s=s;
	        return s;
	    }
	    void permute(string S,int l,int r){
	        if(l==r){
	            v.push_back(S);
	            return ;
	        }
	        for(int i=l;i<=r;++i){
	            S = Swap(S,l,i);
	            permute(S,l+1,r);
	            S= Swap(S,l,i);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		  int l=0,r=S.length()-1;
		  permute(S,l,r);
		  sort(v.begin(),v.end());
		  return v;// Code here there
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