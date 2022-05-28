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
        int n = str1.length();
        string str = str1;
        for(int i = 0 ; i < str.length() ; ++i){
            str1[(i+2)%n] = str[i];
        }
        if(str1 == str2)
            return true;
        for(int i = 0 ; i < str.length() ; ++i){
            str1[(i+n-2)%n] = str[i];
        }
        if(str1 == str2)
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