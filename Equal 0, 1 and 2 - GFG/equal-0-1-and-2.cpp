// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        long long zero = 0, one = 0,two = 0,cnt=0;
        unordered_map<string,int>memo;
        string tmp = "0#0";
        memo[tmp] = 1;
        for(int i=0;i<str.length();++i){
            if(str[i]=='0')
                ++zero;
            if(str[i]=='1')
                ++one;
            if(str[i]=='2')
                ++two;
            string s = to_string(one-zero)+"#"+to_string(two-one);
            if(memo[s]>0){
                cnt+=memo[s];
                memo[s]++;
            }
            else
                memo[s]++;
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}
  // } Driver Code Ends