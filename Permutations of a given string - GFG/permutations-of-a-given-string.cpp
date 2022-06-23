// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	unordered_map<string,int>m;
	void permutation(int index,int n,string S,vector<string>&res){
	    if(index==n){
	        if(m[S]==0)
	        res.push_back(S);
	        m[S]++;
	        return;
	    }
	    for(int i = 0 ; i < S.length() ; ++i){
	        swap(S[index],S[i]);
	        permutation(index+1,n,S,res);
	        swap(S[index],S[i]);
	    }
	    return;
	}
	vector<string>find_permutation(string S)
	{
	    vector<string>res;
	    permutation(0,S.length(),S,res);
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