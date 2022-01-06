// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        string str;
        int n=str2.length();
        for(int i=0;i<n;++i){
            str=str+str2[i];
        }
        for(int i=0;i<n;++i){
            str2[(i+2)%n]=str[i];
        }
        if(str2==str1)
            return true;
    reverse(str.begin(), str.begin()+2);
    reverse(str.begin()+2, str.end());
    reverse(str.begin(), str.end());
    if(str1==str)
        return true;
        return false;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends